#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    char buffer[200];

    int src_fileId = open(argv[1], O_RDONLY);
    int dist_fileId = open(argv[2], O_CREAT | O_WRONLY, 0644);

    int actual_size = 0;

    while ((actual_size = read(src_fileId, buffer, 200)) > 0) {

	write(dist_fileId, buffer, actual_size);

    }

    close(src_fileId);
    close(dist_fileId);
    return 0;
}
