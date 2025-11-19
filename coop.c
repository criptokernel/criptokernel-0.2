#include <libkernel/coop.h>

void task1(task_t* self) {
    TASK_BEGIN();

    while (1) {
        print_string("Task 1 rodando\n");
        TASK_YIELD();
    }

    TASK_END();
}

void task2(task_t* self) {
    TASK_BEGIN();

    while (1) {
        print_string("Task 2 trabalhando\n");
        TASK_YIELD();
    }

    TASK_END();
}

void run() {
    // cria tasks
    create_task(task1);
    create_task(task2);

    // a lista circular já está montada pelo create_task()
    current = task_list;

    // loop infinito do scheduler
    int x = 100;
    while (x > 0) {
        schedule();
        x--;   // alterna task -> task -> task
    }
}

