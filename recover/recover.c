#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
typedef uint8_t BYTE;
#define BLOCK_SIZE 512


int main(int argc, char *argv[])
{
    //check Usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
    }
    
    // Open file
    FILE *file = fopen(argv[1], "r");
    // error check
    if (file == NULL)
    {
        printf("File not Found\n");
        return 1;
    }
    // set to byte
    BYTE buffer[BLOCK_SIZE];
    bool found_first_jpeg = false;
    // counting the index
    int i = 0;
    FILE *Output_file;
    
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        //check the header if new image found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (!found_first_jpeg)
            {
                found_first_jpeg = true;
            }
            else
            {
                fclose(Output_file);
            }
            char File_name[8];
            sprintf(File_name, "%03i.jpg", i++);
            Output_file = fopen(File_name, "w");
            //error check
            if (Output_file == NULL)
            {
                return 1;
            }
            fwrite(buffer, BLOCK_SIZE, 1, Output_file);
        }
        else if (found_first_jpeg)
        {
            //keep writing the previous file
            fwrite(buffer, BLOCK_SIZE, 1, Output_file);
        }
    }
    fclose(Output_file);
    fclose(file);
    
}
