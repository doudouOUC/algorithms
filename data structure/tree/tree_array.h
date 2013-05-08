
/*
 * 二叉搜索树模块的接口
 */

#define TREE_TYPE int //树的值类型

/*
 * 动态分配数组
 */
void createBinaryTree();

/*
 * 向树添加一个新值，参数是需要被添加的值，它必须原先并不在树中
 */
void insert( TREE_TYPE value);

/*
 * 查找一个特定的值，这个值作为第一个参数传递个函数
 */

TREE_TYPE *find( TREE_TYPE value);

/*
 * 执行树的前序遍历，它的参数是一个回调函数指针，他所指向的函数将在树中处理
 * 每个节点被调用，节点的值作为参数传递给这个函数
 */
//void pre_order_traverse( void(*callback)(TREE_TYPE value) );

void pre_order_traverse(int root);

int treeSize();
