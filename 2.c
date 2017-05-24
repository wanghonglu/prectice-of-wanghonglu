#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct card
{
    int Suit;              //花色 
    char Number;            //牌数 
    float Num;               //游戏中的点数 
}Card; 
Card card1[51];              //保存每张扑克的花色，数字，点数 

void Shuffle();               //洗牌 
void Deal();                   //按顺序发牌

/*编写主函数，在主函数中生成顺序排列的52张牌.然后调用洗牌函数进行洗牌，在调用发牌函数向各玩家发牌。*/

int main()
{
printf("   -------------------------------\n");
printf("   ------------欢迎纸牌--------\n");
printf("   --------------------------------\n");


    int i,suit1,temp;
    char again;
    suit1=2;
    for(i=0;i<52;i++)                //生成52张牌 
    {
        if(i%13==0)
            suit1++;                //改变花色 
        card1[i].Suit=suit1;           //保存花色 
        temp=i%13;
        if(temp==0)
            card1[i].Number='A';
        else if(temp==9)
            card1[i].Number='0';
        else if(temp==10)
            card1[i].Number='J';
        else if(temp==11)
            card1[i].Number='Q';
        else if(temp==12)
            card1[i].Number='K';
        else 
            card1[i].Number=temp+'1';
        if(temp>=10)
            card1[i].Num=0.5;
        else
            card1[i].Num=temp+1;
    }
	while( again != 'n' || again !='N' )
    {
      
        Shuffle();              //洗牌 
        Deal();                 //发牌 
        printf("\n继续玩(y/n)?");
        //fflush(stdin);
        scanf("%c",&again);
    }
    getchar();
    return 0;
} 



/*洗牌函数Shuffle将按顺序的52张牌打乱。*/ 
void Shuffle()                //洗牌 
{
    int i,j;
    Card tempcard;
    srand((int) time(0));
    for(i=0;i<52;i++)
    {
        j=rand()%52;              //将牌的顺序打乱，达到洗牌的效果 
        tempcard=card1[j];
        card1[j]=card1[i];
        card1[i]=tempcard;
    } 
}

/*主要函数Deal,该函数中根据游戏者的选择进行发牌，对于AI，程序将根据游戏者的点数决定是否继续要牌。最后，根据双方牌的点数大小判断获胜方。*/
void Deal()                  //按顺序发牌 
{
    int i,iCount=0,iMan=0,iComputer=0,flag=1,flag1=1; 
    char continue1;
    float TotalM=0,TotalC=0;           //统计游戏者和AI的总点数 
    Card Man[18],Computer[18];             //保存游戏者的计算机手中的牌 
    while(flag==1&&iCount<52)             //还有牌 
    {
                                            //游戏者取牌 
        Man[iMan++]=card1[iCount++];           //发一张牌给游戏者 
        TotalM+=Man[iMan-1].Num;              //累加游戏者拿牌的总点数 
                                           //接下来由AI取牌 
        if(iCount>=52)                      //牌以取完 
            flag=0;
        else if(TotalM>10.5)         //若游戏者爆了，则不再要牌了 
            flag1=0;                  //AI不再要牌 
        else
            {
                //若点数小于10.5，且小于游戏者的点数
                if((TotalC<10.5&&TotalC<TotalM)||TotalC<7)         
                {
                    //AI取一张牌 
                    Computer[iComputer++]=card1[iCount++]; 
                    //累计AI取得牌的总点数    
                    TotalC+=Computer[iComputer-1].Num;          
                }
            } 
            printf("\n");
            printf("你的牌：");
            for(i=0;i<iMan;i++)
                    printf(" %c%c",Man[i].Suit,Man[i].Number);
            printf("\n总点数为：%.1f\n",TotalM);
            printf("AI的牌为：");
            for(i=0;i<iComputer;i++)
                printf(" %c%c",Computer[i].Suit,Computer[i].Number);
             printf("\n总点数为：%.1f\n",TotalC);
              //若游戏者点数小于10.5，可继续要牌 
             if(TotalM<10.5)                    
             {
                do
                {
                    printf("还要牌吗(y/n)?");
                    fflush(stdin);
                    scanf("%c",&continue1);
                }while(continue1!='y' &&continue1!='Y' && continue1!='n'&&continue1
                 !='N');
                 if(continue1=='y'||continue1=='Y')
                    flag=1;
                else
                    flag=0;
                if(iCount==52)
                {
                    printf("牌已经发完了！\n");
                    //getch();
                    break;
                }
             }
              else break;
    }   
    while(flag==1&&iCount<52)              //AI根据需要可继续要牌 
    {
        if(TotalM>10.5)                 // 若游戏者爆了，则不再要牌了
            break;
        else
            {
                //若小于10.5，且小于游戏者的点数 
                if(TotalC<10.5&&TotalC<TotalM)   
                {
                    //AI取一张牌 
                    Computer[iComputer++]=card1[iCount++];
                    //累计AI取得牌的总点数     
                    TotalC+=Computer[iComputer-1].Num;      
                }
                else
                    break;
            }
    }
        printf("\n你的牌:");
        for(i=0;i<iMan;i++)
            printf("%c%c",Man[i].Suit,Man[i].Number);
        printf("\n你的总点数：%.1f\n",TotalM);
        printf("AI的牌为：");
        for(i=0;i<iComputer;i++)
            printf("%c%c",Computer[i].Suit,Computer[i].Number);
        printf("\n计算机的总点数为：%.1f\n",TotalC);
        if(TotalM>10.5)                             //游戏者爆了 
            if(TotalC>10.5)                         //计算机爆了 
                printf("\n你赢了！\n");
            else
                printf("\n你输了！\n");
        else if(TotalM==10.5)
            if(TotalC==10.5)
                printf("\n你和AI打成了平手！\n");
            else
                printf("\n你赢了！\n");
        else if(TotalC>10.5)
            printf("\n你赢了！\n");
        else if(TotalC>TotalM)
             printf("\nAI赢了！\n");
        else if(TotalC==TotalM)
            printf("\n你和AI打成了平手！\n"); 
        else 
            printf("\n你赢了！\n");
} 
