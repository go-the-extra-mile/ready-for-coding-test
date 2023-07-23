#include <cmath>
#include <algorithm>

class MaxHeap {
    int lastposition;
    int array[100];

    void add(int obj){
        array[++lastposition] = obj;
        trickle_up(lastposition);
    }

    void swap(int from, int to) {
        int tmp = array[from];
        array[from] = array[to];
        array[to] = tmp;
    }

    void trickle_up(int position){
        if (position == 0) return;
        int parent = (int)(std::floor((position - 1) / 2));
        if (array[position] > array[parent]) {
            swap(position, parent);
            trickle_up(parent);
        }
    }

    int remove(){
        // heap can only remove the root
        int tmp = array[0];
        swap(0, lastposition--);
        trickle_down(0);
        return tmp;
    }

    void trickle_down(int parent){
        int left = 2*parent + 1;
        int right = 2*parent + 2;

        // stop if...
        //  parent has no child
        if (left > lastposition) return;
        //  parent only has left child
        if (left == lastposition){
            if (array[left] > array[parent]) swap(left, parent);
            return;  
        } 
        //  parent has both child and parent is bigger than both
        if (right <= lastposition && std::max(array[left], array[right]) < array[parent]) return;

        // parent has both child and one child is bigger -> swap with bigger child and trickle down
        if (array[left] > array[right] && array[left] > array[parent]) {
            swap(left, parent);
            trickle_down(left);
        }
        else if (array[left] <= array[right] && array[right] > array[parent]) {
            swap(right, parent);
            trickle_down(right);
        }
    }
};