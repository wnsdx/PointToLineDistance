#include <stdio.h>
// #include <src.h>

#define DEBUG 1

int inputDate[80] = {0};

int testpoint[3][2] = {
    {0,3},
    {1,0},
    {1,1},
};

typedef struct pointToLine{
    // int inputDate[80];
    float point[3][2];
    float k;
    float d;
    float kp;
    float dp;
    int len;
}PTL;

int PointToLineDistance(PTL *para){
    para->len = 0;
    int i = 0;
#if DEBUG
    for(i = 0;i < 3 ;i++){
        printf("input x%d:%d\n",i,testpoint[i][0]);
        para->point[i][0]=testpoint[i][0];
        printf("input y%d:%d\n",i,testpoint[i][1]);
        para->point[i][1]=testpoint[i][1];
    }
#else
    for(i = 0;i < 3 ;i++){
        printf("input x%d:",i);
        scanf("%d",&(para->point[i][0]));
        printf("input y%d:",i);
        scanf("%d",&(para->point[i][1]));
    }
#endif
    para->len = i;
    GetSlopeAndOffset(para);
    GetPerpendicularLineSlopAndOffset(para);
    return 0;
}

int GetSlopeAndOffset(PTL *para){
    int x1=para->point[0][0],x2=para->point[1][0],y1=para->point[0][1],y2=para->point[1][1];
    float ku=0,kd=0;
    ku=(y2-y1);
    kd=(x2-x1);
    para->k = ku/kd;
    para->d = y1-(para->k)*x1;
    printf("ku=%.2f\n",ku);
    printf("kd=%.2f\n",kd);
    printf("k=%.2f\n",(para->k));
    printf("d=%.2f\n",(para->d));
    return 0;
}

int GetPerpendicularLineSlopAndOffset(PTL *para){
    float kp=0,dp=0;
    if (para->k != 0){
        kp = (-1)/para->k;
        dp = para->point[2][1] - kp *para->point[2][0];
        para->kp = kp;
        para->dp = dp;
        printf("kp=%.2f\n",(para->kp));
        printf("dp=%.2f\n",(para->dp));
    }

    return 0;
}

int main(void){
    PTL *mem;
    int i=0;
    mem = (PTL *)malloc(sizeof(PTL));
    printf("Start!\n");
    PointToLineDistance(mem);
    printf("len of inputDate:%d\n",mem->len);
    for(i=0; i < mem->len;i++){
        printf("x%d=%.2f,y%d=%.2f\n",i,mem->point[i][0],i,mem->point[i][1]);
    }
    free(mem);
    return 0;
}

