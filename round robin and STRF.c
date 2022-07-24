#include<stdio.h>
void main()
{
	int at[10],rt[10],ch,i,n,bt[10],quantum_time,time=0,count=0,smallest=0,remain=0,endtime=0,flag=0;
	float waiting_time=0.0,tat=0.0,sum_wait=0.0,sum_tat=0.0;
	printf("\n1.round robin\n2.STRF\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	printf("enter the number of processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the arrival time for %d processes\n",i);
		scanf("%d",&at[i]);
		printf("enter the bust time fot %d process\n",i);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	switch(ch)
	{
		case 1:printf("enter the quantum time\n");
			scanf("%d",&quantum_time);
			remain=n;
			printf("process|turnarround time|waiting time\n");
			for(time=0,count=0;remain!=0;)
			{
				if(rt[count]<=quantum_time&&rt[count]>0)
				{
					time+=rt[count];
					rt[count]=0;
					flag=1;
				}
				else if(rt[count]>0)
				{
					time+=quantum_time;
					rt[count]-=quantum_time;
				}
				if(rt[count]==0&&flag==1)
				{
					remain--;
					printf("p[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
					waiting_time+=time-at[count]-bt[count];
					tat+=time-at[count];
					flag=0;
				}
			if(count==n-1)
				count=0;
			else if(at[count+1]<=time)
				count++;
			else
				count=0;
			}
			printf("average wating time is %.2f\n",waiting_time*1.0/n);
			printf("average turn arround time is %.2f\n",tat*1.0/n);
			break;
	case 2:remain=0;
		printf("process|turn arround|waiting\n");
		rt[9]=9999;
		for(time=0;remain!=n;time++)
		{
			smallest=9;
			for(i=0;i<n;i++)
			{
				if(at[i]<=time&&rt[i]<rt[smallest]&&rt[i]>0)
					smallest=i;
			}
			rt[smallest]--;
			if(rt[smallest]==0)
			{
				remain++;
				endtime=time+1;
				printf("p[%d]\t|\t%d\t|\t%d\n",smallest+1,endtime-at[smallest],endtime-bt[smallest]-at[smallest]);
				sum_wait+=endtime-bt[smallest]-at[smallest];
				sum_tat+=endtime-at[smallest];
			}
	}
	printf("average wating time is %.2f\n",sum_wait*1.0/n);
	printf("average turn arround time is %.2f\n",sum_tat*1.0/n);
	break;
}
}