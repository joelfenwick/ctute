// @(for discussion, see~\hyperlink{disc:reversenums}{here})@
#include <stdio.h>
#include <stdlib.h>

/* This is not actually a good way to do this,
   but it demonstrates fseek.
*/
int* read_nums_presize(FILE* in, int* size) {
    /* check the file first to see how many numbers are in it*/
    *size=0;
    int num;
    while (fscanf(in, "%d", &num)==1) {
        (*size)++;
    }
        /* Now go back to the beginning of the file*/
    if (fseek(in, 0, SEEK_SET)) {
        return 0;
    }
    int* nums=malloc(sizeof(int)*(*size));
    int current=0;
    while(fscanf(in, "%d", &nums[current])==1) {
        current++;        
    }
    return nums;
}

int* read_nums(FILE* in, int* size) {
    int capacity=10;
    *size=0;
    int num;
    int* nums=malloc(sizeof(int)*capacity);
    while (fscanf(in, "%d",&num)==1) {
	if (*size==capacity-1) {
            capacity*=2;
            int* temp=malloc(sizeof(int)*capacity);
            for (int i=0;i<*size;++i) {
                temp[i]=nums[i];
            }
            free(nums);
            nums=temp;
	}
        nums[(*size)++]=num;
    }
    return nums;
}

void output_nums(FILE* out, int* nums, int howmany) {
    for (int i=howmany-1;i>=0;i--) {
        fprintf(out, "%d\n", nums[i]);
    }
}

int main(int argc, char** argv) {
    if (argc!=3) {
        fprintf(stderr, "Usage: flip input ouptut\n");
	return 1;
    }
    FILE* fi=fopen(argv[1],"r");
    FILE* fo=fopen(argv[2],"w");
    if (!fi || !fo) {
        fprintf(stderr, "Unable to open file\n");
        return 2;
    }
    int howmany=0;	// how many numbers in the array?
    int* nums=read_nums_presize(fi, &howmany);
    output_nums(fo, nums, howmany);
    if (nums!=0) {
        free(nums);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
