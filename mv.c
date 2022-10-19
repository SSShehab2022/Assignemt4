#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char buffer[200];

    int src_fileId = open(argv[1], O_RDONLY);
    int dist_fileId = open(argv[2], O_CREAT | O_WRONLY, 0644);

    int actual_size = 0;

    while ((actual_size = read(src_fileId, buffer, 200)) > 0) {

	write(dist_fileId, buffer, actual_size);

    }
    char path_buf[255]; 

    getcwd(path_buf, 255);
    strcat(path_buf, "/");
    strcat(path_buf, argv[1]);

    close(src_fileId);
    close(dist_fileId);

    remove(path_buf);

    return 0;
}
