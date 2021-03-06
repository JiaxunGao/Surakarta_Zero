//
// Created by Blue Sky on 4/4/20.
//


#include "ArrayList.h"

ArrayList::ArrayList() {
    start=0;
    length=0;
    attack_num = 0;
    array = (singleMove *)malloc(100*sizeof(singleMove));
}

ArrayList::~ArrayList() {
    free(array);
}

void ArrayList::clear() {
    length=0;
    start=0;
    attack_num = 0;
}

bool ArrayList::unempty(){
    if(size())
        return true;
    else
        return false;
};

int ArrayList::size() {
    return length-start;
}

int ArrayList::att() {
    return attack_num;
}

void ArrayList::push(int from_x,int from_y,int to_x,int to_y){
    array[length].from.x = from_x;
    array[length].from.y = from_y;
    array[length].to.x = to_x;
    array[length].to.y = to_y;
    length++;
};
void ArrayList::push_unrepeat(int from_x,int from_y,int to_x,int to_y){
    for(int a=start;a<length;a++)
    {
        if(array[a].from.x == from_x && array[a].from.y == from_y && array[a].to.x == to_x && array[a].to.y == to_y)
            return;
    }
    array[length].from.x = from_x;
    array[length].from.y = from_y;
    array[length].to.x = to_x;
    array[length].to.y = to_y;
    length++;
    attack_num++;
};

void ArrayList::pop(singleMove &x) {
    x = array[start++];
}

void ArrayList::pull(singleMove &x,int index) {
    x = array[index];
}

void ArrayList::print(){
    for(int a=start;a<length;a++){
        cout<<array[a].from.x<< " "<< array[a].from.y<<" "<<array[a].to.x<<" "<<array[a].to.y<<endl;
    }
}

void ArrayList::fwrite(ofstream *file){
    for(int i = 0; i<length; i++){
        *file<<array[i].from.x<<" "<<array[i].from.y<<" "<<array[i].to.x<<" "<<array[i].to.y<<" ";
    }
    *file<<endl;
}

void ArrayList::print(double *win_array, char *out) {
    int j = 0;
    /*
    for(int i = start; i<length; i++) {
        out += array[i].from.x + " " + array[i].from.y + " " + array[i].to.x + " " + array[i].to.y + win_array[j] + "\n";
        j++;
    }*/
}

bool ArrayList::find(int from_x,int from_y,int to_x,int to_y){
    for(int a=start;a<length;a++){
        if(array[a].from.x == from_x && array[a].from.y == from_y && array[a].to.x == to_x && array[a].to.y == to_y)
            return true;
    }
    return false;
}

