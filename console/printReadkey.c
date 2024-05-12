#include <myReadkey.h>
#include <myTerm.h>
#include <mySimpleComputer.h>

int printReadkey(){
    enum keys key;
    mt_gotoXY (2, 2);
    rk_mytermsave();
    rk_mytermregime(1,1,0,0,1);
    fflush (stdout);
    int tmp = 0;
    int x=2;
    int y=2;
    int cnt = 0;
    int flag = 0;
    while(1){
        if(rk_readkey(&key)==-1){
            continue;
        }
        if(key == KEY_ESC){
            rk_mytermregime(1,0,0,1,1);
            return -1;
        }
        if(key == KEY_ENTER){
            if(flag == 0){
                int tmp2;
                tmp = 0;
                mt_gotoXY (x,y);
                printf("     ");
                fflush (stdout);
                mt_gotoXY (x,y);
                flag = 1;
                rk_readvalue(&tmp2,4);
                fflush (stdout);
                mt_gotoXY (x,y);
                if(sc_memorySet (cnt, tmp2 + 1280)!=0){
                    break;
                }
                printf ("+%04x", ram[cnt]);
                fflush (stdout);
                rk_mytermrestore();
            }
            else{
                flag = 0;
                break;
            }
        }
        if(key == KEY_L){
            int ram_file;
            char buf[15];
            mt_gotoXY (32,2);
            printf("Введите имя файла для сохранить:");
            rk_mytermregime(0,0,10,1,1);
            scanf("%s",buf);
            strcat(buf,".bin");
            fflush(stdout);
            ram_file = open(buf,O_CREAT | O_RDWR, 0666);
            for (int i = 0; i < 128; ++i) { 
                write(ram_file, &ram[i], sizeof(int));
            }
            mt_gotoXY (32,2);
            mt_setdefaultcolor();
            for(int i=0; i<60+sizeof(buf);i++){
                printf(" ");
            }
            fflush(stdout);
            mt_setfgcolor (GREEN);
            mt_setbgcolor (BLACK + 10);
            cnt_command = 0;
            printBigCell(cnt_command);
            printCounters();
            printCommand();
            printDecodedCommand(ram[cnt_command]);
            printTerm(0,1);
            close(ram_file);
            rk_mytermregime(1,1,0,0,1);
            break;
        }
        if(key == KEY_S){
            int ram_file;
            char buf[200];
            mt_gotoXY (32,2);
            printf("Введите имя файла для загрузки:");
            rk_mytermregime(0,0,10,1,1);
            scanf("%s",buf);
            strcat(buf,".bin");
            fflush(stdout);
            ram_file = open(buf, O_RDONLY);
            for (int i = 0; i < 128; i++){
                if (sc_memorySet (i, 0) != 0)
                    return -1;
            }
            for (int i = 0; i < 128; i++) { 
                read(ram_file, &ram[i], sizeof(int)); 
            }
            for (int i = 0; i < 128; i++)
                printCell (i, GREEN, BLACK + 10);
            fflush(stdout);
            mt_gotoXY (32,2);
            mt_setdefaultcolor();
            for(int i=0; i<58+sizeof(buf);i++){
                printf(" ");
            }
            fflush(stdout);
            mt_setfgcolor (GREEN);
            mt_setbgcolor (BLACK + 10);
            cnt_command = 0;
            printBigCell(cnt_command);
            printCounters();
            printCommand();
            printDecodedCommand(ram[cnt_command]);
            printTerm(0,1);
            close(ram_file);
            rk_mytermrestore();
            break;
        }
        if(key == KEY_I){
            raise(SIGUSR1);
            mt_gotoXY (x,y);
            fflush (stdout);
        }
        if(key == KEY_R){
            sc_regSet(3,0);
            printFlags();
            break;
        }
        if(key == KEY_F5){
            tmp = 0;
            mt_gotoXY (3,125);
            printf("    ");
            fflush (stdout);
            mt_gotoXY (3,125);
            flag = 1;
            rk_readvalue(&tmp,4);
            fflush (stdout);
            if(sc_accumulatorSet (tmp)!=0)
                break;
            rk_mytermrestore();
        }
        if(key == KEY_F6){
            mt_gotoXY (6, 140);
            printf("  ");
            fflush (stdout);
            mt_gotoXY (6, 140);
            rk_mytermregime(1,1,0,1,1);
            rk_readvalue(&tmp,5);
            flag = 1;
            if(sc_icounterSet (tmp)!=0)
                break;
            rk_mytermrestore();
        }
        if(key == KEY_DOWN){
            x+=2;
            cnt++;
            if(x>20){
                x=2;
                cnt-=10;
            }
            printDecodedCommand (ram[cnt]);
            printBigCell(cnt);
            sc_icounterSet(cnt);
            printCounters();
            printCommand();
            printTerm (cnt, 1);
            mt_gotoXY (x,y);
            fflush (stdout);
        }
        if(key == KEY_UP){
            x-=2;
            cnt--;
            if(x<=0){
                x=20;
                cnt += 10;
            }
            printDecodedCommand (ram[cnt]);
            printBigCell(cnt);
            sc_icounterSet(cnt);
            printCounters();
            printCommand();
            printTerm (cnt, 1);
            mt_gotoXY (x,y);
            fflush (stdout);
        }
        if(key == KEY_LEFT){
            y-=9;
            cnt-=10;
            if(y<0){
                y=110;
                cnt += 130;
            }
            printDecodedCommand (ram[cnt]);
            printBigCell(cnt);
            sc_icounterSet(cnt);
            printCounters();
            printCommand();
            printTerm (cnt, 1);
            mt_gotoXY (x,y);
            fflush (stdout);
        }
        if(key == KEY_RIGHT){
            y+=9;
            cnt+=10;
            if(y>113){
                y=2;
                cnt -= 130;
            }
            printDecodedCommand (ram[cnt]);
            printBigCell(cnt);
            sc_icounterSet(cnt);
            printCounters();
            printCommand();
            printTerm (cnt, 1);
            mt_gotoXY (x,y);
            fflush (stdout);
        }

    }
    rk_mytermrestore();
    return 0;
}