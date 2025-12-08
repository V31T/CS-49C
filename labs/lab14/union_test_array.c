#include <stdio.h>

typedef enum {
    INT_TYPE,
    FLOAT_TYPE,
} DataType;

typedef union {
    int i;
    float f;
} DataValue;

typedef struct {
    DataType type;
    DataValue value;
} Number;


int main() {
    Number nums[3];

    nums[0].value.i = 3;
    nums[0].type = INT_TYPE;

    nums[1].value.f = 3.14;
    nums[1].type = FLOAT_TYPE;

    nums[2].value.f = 2.71828;
    nums[2].type = FLOAT_TYPE;

    for (int i=0; i<3; i++) {
        if (nums[i].type == INT_TYPE) {
            printf("%d\n", nums[i].value.i);
        } else {
            printf("%f\n", nums[i].value.f);
        }
    }
}

