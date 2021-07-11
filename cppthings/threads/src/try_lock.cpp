//
// Created by sajith on 7/11/21.
//

#include <thread>
#include <mutex>
#include <chrono>


using namespace std;

unsigned int items_on_notepad = 0;
mutex pencil;

void shopper(const char *name)
{
    int item_to_add = 0;
    while (items_on_notepad <= 20)
    {
        if (item_to_add && pencil.try_lock())
        {
//            pencil.lock();
            items_on_notepad += item_to_add;
            printf("%s added %u items(s) to notedpad.\n", name, items_on_notepad);
            item_to_add = 0;
            this_thread::sleep_for(chrono::milliseconds(300));
            pencil.unlock();
        } else
        {
            this_thread::sleep_for(chrono::milliseconds(300));
            item_to_add++;
            printf("%s found something else to buy.\n", name);
        }
    }
}

int main()
{
    auto start_time = chrono::steady_clock::now();
    thread barron(shopper, "Baroon");
    thread olivia(shopper, "Olivia");

    barron.join();
    olivia.join();

    auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count();

    printf("Elapsed time: %.2f seconds.\n", elapsed_time / 1000.0);

    return 0;
}