#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;

	/*write your implementation here*/
	FILE *rf=fopen(filename,"r");
	int num;
	/*if(rf==NULL){
		return 0;
	}*/

	fscanf(rf,"%d",&num);
	*sizePtr=num;

	class_list=(student**)malloc(num*(sizeof(student*)));
	for(int i=0;i<num;i++){
		class_list[i]=(student *)malloc(sizeof(student));
		fscanf(rf,"%d %s %s",&(class_list[i])->student_id, (class_list[i])->first_name, (class_list[i])->last_name);
		class_list[i]->project1_grade=0;
		class_list[i]->project2_grade=0;
		class_list[i]->final_grade=0;
	}
	/* finally return the created class list*/
	fclose(rf);
	return class_list;
}

int find(int idNo, student **list, int size)
{
	for(int i=0;i<size;i++){
		if(list[i]->student_id==idNo)
			return i;
	}
	/*write your implementation here and update the return accordingly*/
	return -1;
}

void input_grades(char *filename, student **list, int size)
{
	int ID,pj1,pj2,index;
	/*write your implementation here*/
	FILE *rf=fopen(filename,"r");
	while(fscanf(rf,"%d",&ID)==1){
		fscanf(rf,"%d %d",&pj1, &pj2);
		index=find(ID,list,size);
		if(index!=-1){
			list[index]->project1_grade=pj1;
			list[index]->project2_grade=pj2;
		}
	}
	fclose(rf);
}

void compute_final_course_grades(student **list, int size)
{
	/*write your implementation here*/
	for(int i=0;i<size;i++){
		list[i]->final_grade=(list[i]->project1_grade+list[i]->project2_grade)/2.0;
	}
}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
	FILE *wf=fopen(filename,"w");
	fprintf(wf,"%d\n",size);
	for(int i=0;i<size;i++){
		fprintf(wf,"%d %f\n",list[i]->student_id,list[i]->final_grade);
	}
	fclose(wf);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int remove=0,i;
	for(i=0;i<*sizePtr;i++){
		if(list[i]->student_id==idNo){
			remove=1;
			break;
		}
	}
	if(remove==1){
		free(list[i]);
		for(i+=1;i<*sizePtr;i++)
			list[i-1]=list[i];
		printf("student with ID number %d was removed\n",idNo)
		*sizePtr=(*sizePtr)-1;

	}
	else
		printf("No student found.");
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for(int i=0;i<*sizePtr;i++){
		free(list[i]);
	}
	free(list);
}
