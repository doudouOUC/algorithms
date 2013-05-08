

#define STACK_TYPE int
/*
 *创建堆栈，参数制定堆栈可以保存元素个数
 *动态数组使用
*/
void create_stack(int size);

/*
 *销毁堆栈，释放堆栈使用的内存
 *动态数组使用
*/
void destroy_stack();

//push
void push(STACK_TYPE value);

//pop
void pop();

//top
STACK_TYPE top();

//is_empty
int is_empty();

//if_full
int is_full();
