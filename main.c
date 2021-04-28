#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct info {
    char id[20];
    char telefon[20];
    char ime[20];
    char priimek[20];
    char datum[20];
    char locilo;
};

int main(int argc, char** argv) {

     if (argc == 1) {
        return 1;
    }


    if (strcmp(argv[1], "-c") == 0) {

        int fd = open("xpo.dat", O_CREAT | O_RDWR , 0777);

        if (fd == -1) {
            perror("Error while creating file");
            exit(EXIT_FAILURE);
        }

    }
    else if (strcmp(argv[1], "-o") == 0 && argc == 15)
    {

        int telindex, imeindex, priimekindex, danindex, mesecindex, letoindex;

        for (int i = 0; i < argc - 1; i++) {
            if (strcmp(argv[i], "-tel") == 0) {
                telindex = i + 1;
            } else if (strcmp(argv[i], "-ime") == 0) {
                imeindex = i + 1;
            } else if (strcmp(argv[i], "-priimek") == 0) {
                priimekindex = i + 1;
            } else if (strcmp(argv[i], "-dan") == 0) {
                danindex = i + 1;
            } else if (strcmp(argv[i], "-mesec") == 0) {
                mesecindex = i + 1;
            } else if (strcmp(argv[i], "-leto") == 0) {
                letoindex = i + 1;
            }
        }
        struct stat file_size;
        int fd = atoi(argv[2]);
        struct info buf;

        fstat(fd, &file_size);
        printf("Size of file: %ld ", file_size.st_size);
        int counter = file_size.st_size / 100 + 1;
        if (file_size.st_size < 100)
        {
            struct info dude;
            memset(&dude.id[0], 0, sizeof(dude.id));
            memset(&dude.telefon[0], 0, sizeof(dude.telefon));
            memset(&dude.ime[0], 0, sizeof(dude.ime));
            memset(&dude.priimek[0], 0, sizeof(dude.priimek));
            memset(&dude.datum[0], 0, sizeof(dude.datum));
            int danVelikost = atoi(argv[danindex]);
            int mesecVelikost = atoi(argv[mesecindex]);

            char date[11];
            for(int i = 0; i < 11; i++)
            {
                date[i] = '\0';
            }
            if(danVelikost < 10)
            {
            strcpy(date, "0");
            strcat(date, argv[danindex]);
            }
            else
            {
            strcpy(date, argv[danindex]);
            }
            strcat(date, ".");

            if(mesecVelikost < 10){
            strcat(date, "0");
            strcat(date, argv[mesecindex]);
            }
            else
            {
            strcat(date, argv[mesecindex]);
            }
            strcat(date, ".");
            strcat(date, argv[letoindex]);

            strcpy(dude.id, "1");
            strcpy(dude.telefon, argv[telindex]);
            strcpy(dude.ime, argv[imeindex]);
            strcpy(dude.priimek, argv[priimekindex]);
            strcpy(dude.datum, date);
            dude.locilo = ';';
            lseek(fd, 0, SEEK_END);
            write(fd, &dude, sizeof(dude));

        }
        else
        {
            struct info dude;
            memset(&dude.id[0], 0, sizeof(dude.id));
            memset(&dude.telefon[0], 0, sizeof(dude.telefon));
            memset(&dude.ime[0], 0, sizeof(dude.ime));
            memset(&dude.priimek[0], 0, sizeof(dude.priimek));
            memset(&dude.datum[0], 0, sizeof(dude.datum));

            char date[9];
            for(int i = 0; i < 0; i++)
            {
                date[i] = '\0';
            }
            int danVelikost = atoi(argv[danindex]);
            int mesecVelikost = atoi(argv[mesecindex]);
            char idCounter[sizeof(int)];
            sprintf(idCounter, "%d", counter);
             if(danVelikost < 10)
            {
            strcpy(date, "0");
            strcat(date, argv[danindex]);
            }
            else
            {
            strcpy(date, argv[danindex]);
            }
            strcat(date, ".");

            if(mesecVelikost < 10){
            strcat(date, "0");
            strcat(date, argv[mesecindex]);
            }
            else
            {
            strcat(date, argv[mesecindex]);
            }
            strcat(date, ".");
            strcat(date, argv[letoindex]);
            lseek(fd, file_size.st_size, SEEK_SET);
            strcpy(dude.id, idCounter);
            strcpy(dude.telefon, argv[telindex]);
            strcpy(dude.ime, argv[imeindex]);
            strcpy(dude.priimek, argv[priimekindex]);
            strcpy(dude.datum, date);
            dude.locilo = ';';

            lseek(fd, 0, SEEK_END);

            int wr = write(fd, &dude, sizeof(dude));
            
        }
        int cl = close(fd);
    }
    else if(strcmp(argv[1], "-o") == 0 && argc == 17)
    {

        int telindex, imeindex, priimekindex, danindex, mesecindex, letoindex, idindex;

        for (int i = 0; i < argc - 1; i++) {
            if (strcmp(argv[i], "-tel") == 0) {
                telindex = i + 1;
            } else if (strcmp(argv[i], "-ime") == 0) {
                imeindex = i + 1;
            } else if (strcmp(argv[i], "-priimek") == 0) {
                priimekindex = i + 1;
            } else if (strcmp(argv[i], "-dan") == 0) {
                danindex = i + 1;
            } else if (strcmp(argv[i], "-mesec") == 0) {
                mesecindex = i + 1;
            } else if (strcmp(argv[i], "-leto") == 0) {
                letoindex = i + 1;
            } else if (strcmp(argv[i], "-id") == 0) {
                idindex = i + 1;
            }
        }
        struct stat file;
        struct info buf;
        int idNum = atoi(argv[idindex]);
        int offsetChange = (idNum * 100) + idNum;

        printf("Offset for delete: %d", offsetChange);
        int fd = atoi(argv[2]);
        struct info dude;
        fstat(fd, &file);
        if(idNum * 100 <= file.st_size)
        {

        memset(&dude.id[0], 0, sizeof(dude.id));
        memset(&dude.telefon[0], 0, sizeof(dude.telefon));
        memset(&dude.ime[0], 0, sizeof(dude.ime));
        memset(&dude.priimek[0], 0, sizeof(dude.priimek));
        memset(&dude.datum[0], 0, sizeof(dude.datum));
        int wr = read(fd, &buf, sizeof buf);
        char date[9];
        for(int i = 0; i < 0; i++)
        {
            date[i] = '\0';
        }
        lseek(fd, offsetChange, SEEK_SET);

        int danVelikost = atoi(argv[danindex]);
            int mesecVelikost = atoi(argv[mesecindex]);
             if(danVelikost < 10)
            {
            strcpy(date, "0");
            strcat(date, argv[danindex]);
            }
            else
            {
            strcpy(date, argv[danindex]);
            }
            strcat(date, ".");

            if(mesecVelikost < 10){
            strcat(date, "0");
            strcat(date, argv[mesecindex]);
            }
            else
            {
            strcat(date, argv[mesecindex]);
            }
            strcat(date, ".");
            strcat(date, argv[letoindex]);

        strcpy(dude.id, argv[idindex]);
        strcpy(dude.telefon, argv[telindex]);
        strcpy(dude.ime, argv[imeindex]);
        strcpy(dude.priimek, argv[priimekindex]);
        strcpy(dude.datum, date);
        dude.locilo = ';';
        pwrite(fd,&dude, 100, offsetChange - 101);
        int cl = close(fd);
        }
        else{
            return 0;
        }
    }
    else if (strcmp(argv[1],"-o") == 0 && argc < 15 && strcmp(argv[3],"-id") == 0) {
        struct info dude;
        struct info buf;
        struct stat file_size;
        int idNum = atoi(argv[4]);
        int fd = atoi(argv[2]);
        fstat(fd, &file_size);
        if (file_size.st_size > idNum * 100) {


            int wr = read(fd, &buf, sizeof buf);
            int offsetChange = (idNum * 100) + idNum;
            lseek(fd, offsetChange, SEEK_SET);
            memset(dude.telefon, 0x00, 20);
            memset(dude.ime, 0x00, 20);
            memset(dude.priimek, 0x00, 20);
            memset(dude.datum, 0x00, 20);
            memset(dude.id,0x00, 20);
            dude.locilo = '\0';

            pwrite(fd, &dude, 100, offsetChange - 101);
            int cl = close(fd);

        }
    }
    else if(strcmp(argv[1], "-o") == 0 && argc < 15 && (strcmp(argv[3], "-ime")== 0  || strcmp(argv[3], "-priimek") == 0))
    {
        int imeIndex, priimekIndex;
        for (int i = 0; i < argc - 1; i++) {
            if (strcmp(argv[i], "-ime") == 0) {
                imeIndex = i + 1;
            } else{
                imeIndex = 0;
            }
        }  
        for(int j = 0; j < argc - 1; j++){
             if (strcmp(argv[j], "-priimek") == 0) 
             {
                priimekIndex = j + 1;
            } 
            else
            {
                priimekIndex = 0;
            }
        }

        struct stat file;
        int fd = atoi(argv[2]);
        fstat(fd,&file);
        int entries = (int)file.st_size / 101;
        int offset = 0;
        struct info buf;
        for(int i = 0; i < entries; i++){

            lseek(fd, offset, SEEK_SET);
            int rd = read(fd,&buf,101);
            if( (imeIndex != 0 && strcmp(argv[imeIndex],buf.ime) == 0 && priimekIndex == 0)  || ( imeIndex == 0 && priimekIndex != 0 && strcmp(argv[priimekIndex], buf.priimek) == 0) || 
                (strcmp(argv[imeIndex],buf.ime) == 0 && strcmp(argv[priimekIndex],buf.priimek) == 0 && imeIndex != 0 && priimekIndex != 0)){
                

                printf("%s\t%s\t%s\t%s\t%s\n", buf.id, buf.telefon, buf.ime, buf.priimek, buf.datum);
            }
            offset = 101 + offset;
        }
        close(fd);

    }
        
    
    return 0;
}