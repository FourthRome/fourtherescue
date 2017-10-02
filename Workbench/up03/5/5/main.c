#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

typedef struct Node
{
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
} Node;

Node
read_node(int fd, int32_t idx)
{
    Node res;
    if (lseek(fd, idx * sizeof(res), SEEK_SET) == -1) {
        return NULL;
    }
    char buf[sizeof(res)];
    if (read(fd, buf, sizeof(res)))

}

void
print_tree_keys(int fd, int32_t idx)
{
    Node = read_node(fd, idx);
    if (Node == NULL) {
        return;
    } else {
        print_tree_keys(fd, Node.left_idx);
        printf("%d\n", Node.key);
        print_tree_keys(fd, Node.right_idx);
    }
}

int
main(void)
{
    if (argc != 2) {
        return 1;
    }

    int input = open(argv[1], O_RDONLY);
    print_tree_keys(fd, 0);
    close(input);
    
    return 0;
}