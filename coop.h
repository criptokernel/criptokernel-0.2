#define TASK_BEGIN() switch(self->state) { case 0:
#define TASK_YIELD() do { self->state = __LINE__; return; case __LINE__:; } while (0)
#define TASK_END() } self->finished = 1; return;

// declarações vindas do kernel
typedef struct task {
    int state;
    int finished;
    void (*run)(struct task* self);
    struct task* next;
} task_t;

extern task_t* task_list;
extern task_t* current;

task_t* create_task(void (*fn)(task_t*));
void schedule();

