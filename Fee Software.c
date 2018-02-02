#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int privatecollege();
int governmentcollege();
struct student
{
char name[20];
char clas[20];
char phy[20];
char maths[20];
char chem[20];
char bio[20];
char islam[20];
char pak[20];
char english[20];
char urdu[20];
int total,fphy,fmaths,fchem,fbio,fislam,fpak,fenglish,furdu,off,give,remaining,netfee;
};
struct student data;
int main ()
{
	int choice;
	printf("Please enter the name of student:");
	scanf("%s",data.name);
	printf("\nEnter 1 for Private College Students:\nEnter 2 for Govt.College Students.\n\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);
	int w=0;
	while(w==0){
	switch(choice){
               case 1:
                    {
                        privatecollege();
                        w=1;
                        break;
                    }
               case 2:
                    {
                        governmentcollege();
                        w=1;
                        break;
                    }
                default:
                    {
                        printf("Please Enter Correct Option:\n");

                    }
                }
        }

}
int privatecollege()
    {
        int w=0,num,subselect,feescience,feearts,totalscisub,totalartssub, feeoption,change,peroff;
        int total,off,give,remaining,optional;
        int i;
        FILE *p;
        char n[20]="Student Name:";
        char sig[20]="Signature:";
        char st[50]="Private College Student";
        char tf[20]="Total Fee:";
        char ad[30]="ADVANCE COACHING CENTER";
        char nl[5]="\n";
        char t[5]="\t";
        char s[10]="Subjects";
        char f[15]="FeeDetails";
        char c[15]="Concession:";
        char pb[15]="Payable:";
        char r[15]="Remaining:";
        char nf[15]="Net Fee:";
        char bytwo[5]=" X 2";
        p = fopen("STUDENT FEE RECIEPT.txt", "w");
        fprintf(p,"%s%s%s",nl,st,nl);
        fprintf(p,"%s%s",nl,n);
        fprintf(p," %s%s",data.name,nl);
        fprintf(p,"%s%s%s%s%s",nl,s,t,f,nl);
        feescience=1500;
        feearts=1500;
        totalscisub=0;
        totalartssub=0;
        printf("Enter Number of Subjects");
        scanf("%d",&num);
        if(num==1 || num==2)
        {
            feescience=feescience;
            data.fphy=1500;
            data.fmaths=1500;
            data.fchem=1500;
            data.fbio=1500;
            data.fislam=1500;
            data.fpak=1500;
            data.fenglish=1500;
            data.furdu=1500;
        }
        else
        {
            feescience=1350;
            feearts=1350;
            data.fphy=1500;
            data.fmaths=1500;
            data.fchem=1500;
            data.fbio=1500;
            data.fislam=1500;
            data.fpak=1500;
            data.fenglish=1500;
            data.furdu=1500;
        }
        for(i=0;i<num;i++)
        {
            system("cls");
            printf("\nPlease Choose Subject No. %d",i+1);
            printf("\nEnter 1 for Physics:\nEnter 2 for Maths:\nEnter 3 for Chemistry:\nEnter 4 for Biology:\nEnter 5 for English:\nEnter 6 for Urdu:\nEnter 7 for Islamic Studies:\nEnter 8 for Pak Studies:");
            scanf("%d",&subselect);
            system("cls");
            switch(subselect)
            {
            case 1:
                {
                   strncpy(data.phy,"Physics",20);
                   fprintf(p,"%s%s%s%s%d%s",nl,data.phy,t,t,data.fphy,bytwo);
                   break;
                }
            case 2:
                {
                  strncpy(data.maths,"Mathematics",20);
                  fprintf(p,"%s%s%s%d%s",nl,data.maths,t,data.fmaths,bytwo);
                  break;
                }
            case 3:
                {
                  strncpy(data.chem,"Chemistry",20);
                  fprintf(p,"%s%s%s%d%s",nl,data.chem,t,data.fchem,bytwo);
                  break;
                }
            case 4:
                {
                  strncpy(data.bio,"Biology",20);
                  fprintf(p,"%s%s%s%s%d%s",nl,data.bio,t,t,data.fbio,bytwo);
                  break;
                }
            case 5:
                {
                  strncpy(data.english,"English",20);
                  fprintf(p,"%s%s%s%s%d%s",nl,data.english,t,t,data.fenglish,bytwo);
                  break;
                }
            case 6:
                {
                    totalartssub++;
                    strncpy(data.urdu,"Urdu",20);
                    fprintf(p,"%s%s%s%s%d%s",nl,data.urdu,t,t,data.furdu,bytwo);
                    break;
                }
            case 7:
                {
                    totalartssub++;
                    strncpy(data.islam,"Islamic Studies",20);
                    fprintf(p,"%s%s%s%d%s",nl,data.islam,t,data.fislam,bytwo);
                    break;
                }
            case 8:
                {
                    totalartssub++;
                    strncpy(data.pak,"Pak Studies",20);
                    fprintf(p,"%s%s%s%d%s",nl,data.pak,t,data.fpak,bytwo);
                    break;
                }
            default:
                {
                    printf("Please Enter Correct Correct Option");
                    i=i-1;
                    break;
                }

            }

        }

    total=num*3000;
    give=num*feearts*2;
    off=total-give;
    printf("Total=%f",total);
    data.total=total;
    data.off=off;
    data.netfee=give;
    data.remaining=remaining;
    system("cls");
    printf("Please enter 1 for Total Fee in advance before date:\n");
    printf("Please enter 2 for Total Fee in advance after date:\n");
    printf("Please enter 3 for 70per Fee in advance before date:\n");
    printf("Please enter 4 for 70per Fee in advance after date:\n");
    scanf("%d",&feeoption);
    while(w==0){
    switch(feeoption){
               case 1:
                    {
                        peroff=(total*(0.15));
                        data.off=(off)+(peroff)+1;
                        data.netfee=(give)-(peroff)-1;
                        data.give=data.netfee;
                        data.remaining=0;
                        w=1;
                        break;
                    }
               case 2:
                    {
                        peroff=(total*(0.05));
                        data.off=(off)+(peroff);
                        data.netfee=(give)-(peroff);
                        data.give=data.netfee;
                        data.remaining=0;
                        w=1;
                        break;
                    }
               case 3:
                    {
                        peroff=(total*(0.10));
                        data.off=(off)+(peroff);
                        optional=(give)-(peroff)+1;
                        data.netfee=optional;
                        change=(optional*0.30);
                        data.give=(optional*0.70);
                        data.remaining=change;
                        w=1;
                        break;
                    }
               case 4:
                    {
                        peroff=0;
                        data.off=(off)+(peroff);
                        optional=(give)-(peroff)+1;
                        data.netfee=optional;
                        change=(optional*0.30);
                        data.give=(optional*0.70);
                        data.remaining=change;
                        w=1;
                        break;
                    }
                default:
                    {
                        printf("Please Enter Correct Option:\n");

                    }
                }
	}

        fprintf(p,"%s%s%s%s%d",nl,nl,tf,t,data.total);
        fprintf(p,"%s%s%s%d",nl,c,t,data.off);
        fprintf(p,"%s%s%s%d",nl,nf,t,data.netfee);
        fprintf(p,"%s%s%s%d",nl,pb,t,data.give);
        fprintf(p,"%s%s%s%d",nl,r,t,data.remaining);
        fprintf(p,"%s%s%s%s",nl,nl,t,ad);
        fprintf(p,"%s%s%s",nl,nl,sig);
        fclose(p);
    }
int governmentcollege()
{
    int w=0,num,subselect,feescience,feearts,totalscisub,totalartssub, feeoption,change,peroff;
        int total,off,give,remaining,optional;
        int i;
        FILE *p;
        char n[20]="Student Name:";
        char sig[20]="Signature:";
        char st[50]="Govt. College Student";
        char tf[20]="Total Fee:";
        char ad[30]="ADVANCE COACHING CENTER";
        char nl[5]="\n";
        char t[5]="\t";
        char s[10]="Subjects";
        char f[15]="FeeDetails";
        char c[15]="Concession:";
        char pb[15]="Payable:";
        char r[15]="Remaining:";
        char nf[15]="Net Fee:";
        char bytwo[5]=" X 2";
        p = fopen("STUDENT FEE RECIEPT.txt", "w");
        fprintf(p,"%s%s%s",nl,st,nl);
        fprintf(p,"%s%s",nl,n);
        fprintf(p," %s%s",data.name,nl);
        fprintf(p,"%s%s%s%s%s",nl,s,t,f,nl);
        feescience=1275;
        feearts=1275;
        totalscisub=0;
        totalartssub=0;
        printf("Enter Number of Subjects");
        scanf("%d",&num);
        if(num==1 || num==2)
        {
            feescience=feescience;
            feearts=feearts;
            data.fphy=1500;
            data.fmaths=1500;
            data.fchem=1500;
            data.fbio=1500;
            data.fislam=1500;
            data.fpak=1500;
            data.fenglish=1500;
            data.furdu=1500;
        }
        else
        {
            feescience=1125;
            feearts=1125;
            data.fphy=1500;
            data.fmaths=1500;
            data.fchem=1500;
            data.fbio=1500;
            data.fislam=1500;
            data.fpak=1500;
            data.fenglish=1500;
            data.furdu=1500;
        }
        for(i=0;i<num;i++)
        {
            system("cls");
            printf("\nPlease Choose Subject No. %d",i+1);
            printf("\nEnter 1 for Physics:\nEnter 2 for Maths:\nEnter 3 for Chemistry:\nEnter 4 for Biology:\nEnter 5 for English:\nEnter 6 for Urdu:\nEnter 7 for Islamic Studies:\nEnter 8 for Pak Studies:");
            scanf("%d",&subselect);
            system("cls");
            switch(subselect)
            {
            case 1:
                {
                   strncpy(data.phy,"Physics",20);
                   fprintf(p,"%s%s%s%s%d%s",nl,data.phy,t,t,data.fphy,bytwo);
                   break;
                }
            case 2:
                {
                  strncpy(data.maths,"Mathematics",20);
                  fprintf(p,"%s%s%s%d%s",nl,data.maths,t,data.fmaths,bytwo);
                  break;
                }
            case 3:
                {
                  strncpy(data.chem,"Chemistry",20);
                  fprintf(p,"%s%s%s%d%s",nl,data.chem,t,data.fchem,bytwo);
                  break;
                }
            case 4:
                {
                  strncpy(data.bio,"Biology",20);
                  fprintf(p,"%s%s%s%s%d%s",nl,data.bio,t,t,data.fbio,bytwo);
                  break;
                }
            case 5:
                {
                  strncpy(data.english,"English",20);
                  fprintf(p,"%s%s%s%s%d%s",nl,data.english,t,t,data.fenglish,bytwo);
                  break;
                }
            case 6:
                {
                    totalartssub++;
                    strncpy(data.urdu,"Urdu",20);
                    fprintf(p,"%s%s%s%s%d%s",nl,data.urdu,t,t,data.furdu,bytwo);
                    break;
                }
            case 7:
                {
                    totalartssub++;
                    strncpy(data.islam,"Islamic Studies",20);
                    fprintf(p,"%s%s%s%d%s",nl,data.islam,t,data.fislam,bytwo);
                    break;
                }
            case 8:
                {
                    totalartssub++;
                    strncpy(data.pak,"Pak Studies",20);
                    fprintf(p,"%s%s%s%d%s",nl,data.pak,t,data.fpak,bytwo);
                    break;
                }
            default:
                {
                    printf("Please Enter Correct Correct Option");
                    i=i-1;
                    break;
                }

            }

        }
    total=num*3000;
    give=num*feearts*2;
    off=total-give;
    printf("Total=%f",total);
    data.total=total;
    data.off=off;
    data.give=give;
    data.remaining=remaining;
    system("cls");
    printf("Please enter 1 for Total Fee in advance before date:\n");
    printf("Please enter 2 for Total Fee in advance after date:\n");
    printf("Please enter 3 for 70per Fee in advance before date:\n");
    printf("Please enter 4 for 70per in advance after date:\n");
    scanf("%d",&feeoption);
    while(w==0){
    switch(feeoption){
               case 1:
                    {
                        peroff=(total*(0.15));
                        data.off=(off)+(peroff)+1;
                        data.netfee=(give)-(peroff)-1;
                        data.give=data.netfee;
                        data.remaining=0;
                        w=1;
                        break;
                    }
               case 2:
                    {
                        peroff=(total*(0.05));
                        data.off=(off)+(peroff);
                        data.netfee=(give)-(peroff);
                        data.give=data.netfee;
                        data.remaining=0;
                        w=1;
                        break;
                    }
               case 3:
                    {
                        peroff=(total*(0.10));
                        data.off=(off)+(peroff);
                        optional=(give)-(peroff)+1;
                        data.netfee=optional;
                        change=(optional*0.30);
                        data.give=(optional*0.70);
                        data.remaining=change;
                        w=1;
                        break;
                    }
               case 4:
                    {
                        peroff=0;
                        data.off=(off)+(peroff);
                        optional=(give)-(peroff)+1;
                        data.netfee=optional;
                        change=(optional*0.30);
                        data.give=(optional*0.70);
                        data.remaining=change;
                        w=1;
                        break;
                    }
                default:
                    {
                        printf("Please Enter Correct Option:\n");

                    }
                }
	}

        fprintf(p,"%s%s%s%s%d",nl,nl,tf,t,data.total);
        fprintf(p,"%s%s%s%d",nl,c,t,data.off);
        fprintf(p,"%s%s%s%d",nl,nf,t,data.netfee);
        fprintf(p,"%s%s%s%d",nl,pb,t,data.give);
        fprintf(p,"%s%s%s%d",nl,r,t,data.remaining);
        fprintf(p,"%s%s%s%s",nl,nl,t,ad);
        fprintf(p,"%s%s%s",nl,nl,sig);
        fclose(p);
}
