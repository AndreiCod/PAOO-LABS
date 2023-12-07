#include <iostream>
#include <string.h>
#include <vector>

#include <complex>
#include <memory>
#include <thread>
#include <GLFW/glfw3.h>

int size_x = 800, size_y = 800, max_iter = 1000;
const double x_min = -2.0, x_max = 1.0, y_min = -1.5, y_max = 1.5;

const int MAX_THREADS = 8;
std::counting_semaphore<MAX_THREADS> sem(MAX_THREADS);

std::pair<int, int> get_coordinate(int pos)
{
    int x = pos / size_x;
    int y = pos % size_y;
    return std::make_pair(x, y);
}

int get_position(int x, int y)
{
    return x * size_x + y;
}

void mandelbrot(int pos, std::shared_ptr<int[]> image_ptr)
{
    std::pair<int, int> coord = get_coordinate(pos);
    int x = coord.first;
    int y = coord.second;

    std::complex<double> z = 0;
    std::complex<double> c((double)x / size_x * (x_max - x_min) + x_min, (double)y / size_y * (y_max - y_min) + y_min);
    int iter = 0;
    while (abs(z) < 2 && iter < max_iter)
    {
        z = z * z + c;
        iter++;
    }

    image_ptr[pos] = iter;

    sem.release();
}

void mandelbrot_thread(std::shared_ptr<int[]> image_ptr)
{
    for (int i = 0; i < size_x * size_y; i++)
    {
        std::shared_ptr<int[]> image_ptr_copy(image_ptr);
        sem.acquire();
        std::thread t(mandelbrot, i, image_ptr_copy);
        t.detach();
    }
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-s") == 0)
        {
            size_x = atoi(argv[i + 1]);
            size_y = atoi(argv[i + 2]);
        }
        if (strcmp(argv[i], "-m") == 0)
        {
            max_iter = atoi(argv[i + 1]);
        }
    }

    // allocate memory for the image
    std::shared_ptr<int[]> image_ptr(new int[size_x * size_y]);

    // calculate the image
    std::thread t(mandelbrot_thread, image_ptr);
    t.detach();

    // print the image
    GLFWwindow *window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(size_x, size_y, "Mandelbrot Set", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POINTS);
        for (int i = 0; i < size_x * size_y; i++)
        {
            std::pair<int, int> coord = get_coordinate(i);
            int x = coord.first;
            int y = coord.second;

            double grey_value = (double)image_ptr[i] / max_iter;

            glColor3d(grey_value, grey_value, grey_value);
            glVertex2f(double(x) / size_x * 2 - 1, double(y) / size_y * 2 - 1);
        }
        glEnd();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}