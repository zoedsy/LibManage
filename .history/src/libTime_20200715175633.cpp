#include"../include/libTime.h"
namespace LibSys{
    std::string getTime(){
        time_t timep;
        time(&timep);
        char tmp[64];
        strftime(tmp, sizeof(tmp), "%Y/%m/%d %H/%M/%S", localtime(&timep));
        return tmp;
    }
    int TimeSub(char a[20],char b[20])
    {
        char Year1[5],Mon1[3],Day1[3],Hour1[3],Min1[3],Sec1[3];
        int year1,mon1,day1,hour1,min1,sec1,i,j;
        for(i=0;a[i]!=0 && a[i]!='/';i++){
            Year1[i]=a[i];
        }	
        Year1[i]=0;
        year1=atoi(Year1);

        i++;
        for( j=0;a[i]!=0 && a[i]!='/';i++){
            Mon1[j]=a[i];
            j++;
        }
        Mon1[j]=0;
        mon1=atoi(Mon1);
        i++;

        for(j=0;a[i]!='\0' && a[i]!='/'&& i<10;i++){
            Day1[j]=a[i];
            j++;
        }
        Day1[j]=0;
        day1=atoi(Day1);
        i++;

        for(j=0;i<=12;i++){
            Hour1[j]=a[i];
            j++;
        }
        Hour1[j]=0;
        hour1=atoi(Hour1);
        i++;
        for(j=0;a[i]!='/';i++){
            Min1[j]=a[i];
            j++;
        }
        Min1[j]=0;
        min1=atoi(Min1);
        i++;

        for(j=0;i<=19;i++){
            Sec1[j]=a[i];
            j++;
        }
        Sec1[j]=0;
        sec1=atoi(Sec1);
        char Year2[5],Mon2[3],Day2[3],Hour2[3],Min2[3],Sec2[3];
        int year2,mon2,day2,hour2,min2,sec2;
        for( i=0;b[i]!=0 && b[i]!='/';i++){
            Year2[i]=b[i];
        }	
        Year2[i]=0;
        year2=atoi(Year2);
        i++;
        for(j=0;i<10 && b[i]!='/';i++){
            Mon2[j]=b[i];
            j++;
        }
        Mon2[j]=0;
        mon2=atoi(Mon2);
        i++;
        for(j=0;i<10 && b[i]!='/';i++){
            Day2[j]=b[i];
            j++;
        }
        Day2[j]=0;
        day2=atoi(Day2);
        i++;
        for(j=0;i<=12 && b[i]!='/';i++){
            Hour2[j]=b[i];
            j++;
        }
        Hour2[j]=0;
        hour2=atoi(Hour2);
        i++;
        for(j=0;b[i]!='/';i++){
            Min2[j]=b[i];
            j++;
        }
        Min2[j]=0;
        min2=atoi(Min2);
        i++;
        for(j=0;i<=19;i++){
            Sec2[j]=b[i];
            j++;
        }
        Sec2[j]=0;
        sec2=atoi(Sec2);
        int subday,subhour,submin,subsec;
        subday=day_diff(year1,mon1,day1,year2,mon2,day2);
        subsec=(sec2-sec1)+(min2-min1)*60+(hour2-hour1)*3600;
        if(subsec<0){
            subsec=24*3600+subsec;
            subday--;
        }
        subhour=subsec/3600;
        submin=(subsec%3600)/60;
        subsec=(subsec%3600)%60;
        if(subhour>=24){
            subhour=subhour%24;
            subday=subday+subhour/24;
        }
        
        printf("%d days %d hours %d mins %d secs\n",subday,subhour,submin,subsec);
        return 0;
        
    }

    int day_diff(int year_start, int month_start, int day_start
                , int year_end, int month_end, int day_end)
    {
        int y2, m2, d2;
        int y1, m1, d1;
        
        m1 = (month_start + 9) % 12;
        y1 = year_start - m1/10;
        d1 = 365*y1 + y1/4 - y1/100 + y1/400 + (m1*306 + 5)/10 + (day_start - 1);
    
        m2 = (month_end + 9) % 12;
        y2 = year_end - m2/10;
        d2 = 365*y2 + y2/4 - y2/100 + y2/400 + (m2*306 + 5)/10 + (day_end - 1);
        
        return (d2 - d1);
    }
}