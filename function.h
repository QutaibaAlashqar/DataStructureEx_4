

/// QUTAIBA ALASHQAR, 20290036.
/// LAB_4, DATA STRUCRUE;


struct nodeStudent{
    int studentID;
    int term;
    struct nodeStudent* next;
};


struct nodeClass{
    int classID;
    double classtermAverage;
    struct nodeClass* next;
    struct nodeStudent* studentPtr;
};


int insert(struct nodeClass** head, int stu_num, int puan){
    int flag = 0;

    struct nodeClass (*node1) = malloc(sizeof(struct nodeClass));

    int class_num;
    int number_of = (stu_num / 10000);

    if(number_of == 6){

        class_num = 1;
        node1-> classID = class_num;
        node1-> studentPtr = NULL;
        node1-> next = NULL;
    }

    if(number_of == 7){

        class_num = 2;
        node1-> classID = class_num;
        node1-> studentPtr = NULL;
        node1-> next = NULL;
    }

    if(number_of == 8){

        class_num = 3;
        node1-> classID = class_num;
        node1-> studentPtr = NULL;
        node1-> next = NULL;
    }

    if(number_of == 9){

        class_num = 4;
        node1-> classID = class_num;
        node1-> studentPtr = NULL;
        node1-> next = NULL;
    }

    ////
    int gonder = 0;
    if((flag == 0) && ((*head) == NULL)){

        flag = 1;
        (*head) = node1;
        gonder = (&(node1-> studentPtr));
        insertStudent(gonder, stu_num, puan);
        gonder = 0;
        return 0;
    }

    if((flag == 0) && (class_num < (*head)-> classID)){

        flag = 1;
        node1-> next = (*head);
        (*head) = node1;
        gonder = (&(node1-> studentPtr));
        insertStudent(gonder, stu_num, puan);
        gonder = 0;
        return 0;
    }

    ////

    struct nodeClass* data1 = *head;
    int gonder2 = 0;

    while(data1-> next != NULL){

        if(class_num == data1-> classID){

            gonder2 = (&(data1-> studentPtr));
            insertStudent(gonder2, stu_num, puan);
            gonder2 = 0;
            return 0;
        }

        if(class_num < (data1-> next-> classID)){

            node1-> next = data1-> next;
            data1-> next = node1;
            gonder = (&(node1-> studentPtr));
            insertStudent(gonder, stu_num, puan);
            gonder = 0;
            return 0;
        }
        data1 = data1-> next;
    }

    if(class_num == data1-> classID){

        gonder2 = (&(data1-> studentPtr));
        insertStudent(gonder2, stu_num, puan);
        gonder2 = 0;
        return 0;
    }

    data1-> next = node1;
    gonder = (&(node1-> studentPtr));
    insertStudent(gonder, stu_num, puan);
}


int insertStudent(struct nodeStudent (**head), int stu_num, int puan){

    struct nodeStudent (*node) = malloc(sizeof(struct nodeStudent));

    node-> studentID = stu_num;
    node-> term = puan;
    node-> next = NULL;

    if((*head) == NULL){

        (*head) = node;
        return 0;
    }

    if (puan > ((*head)-> term)){

        node-> next = (*head);
        (*head) = node;
        return 0;
    }

    struct nodeStudent (*data2) = (*head);

    while((data2-> next) != NULL){

        if (puan > data2-> next-> term){

            node-> next = data2-> next;
            data2-> next = node;
            return 0;
        }
        data2 = data2-> next;
    }
    data2-> next = node;
}


void computeClassAverage(struct nodeClass (*head)){

    struct nodeClass (*data3) = head;

    while(data3 != NULL){

        int total = 0;
        int counter = 0;
        struct nodeStudent (*data4) = data3-> studentPtr;

        while(data4 != NULL){

            total += data4-> term;
            data4 = data4-> next;
            counter++;
        }

        data3-> classtermAverage = ((float)total / counter);
        data3 = data3-> next;

        total = 0;
        counter = 0;
    }
}


void printAll(struct nodeClass (*head)){

    struct nodeClass (*data5) = head;

    while(data5 != NULL){

        struct nodeStudent (*data6) = data5-> studentPtr;
        int out1 = data5-> classID;
        float out2 = data5-> classtermAverage;
        printf("%d %.2f\n", out1, out2);

        while(data6 != NULL){

            int out3 = data6-> studentID;
            int out4 = data6-> term;
            printf("%d %d\n", out3, out4);
            data6 = data6-> next;
        }
        data5 = data5-> next;
    }
}

