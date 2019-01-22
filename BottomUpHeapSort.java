public class BottomUpHeapSort {
    public static void main(String args[]){
        int[] array = {11, 10, 9, 8, 2, 6, 5, 4, 3, 1};
        BottomUp(array);
    }

    static int[] BottomUp (int[]array){
        int n = array.length;

        for(int i=(n/2);i>=1;i--){
            int k =i;
            int v = array[k-1];
            boolean Heap = false;

            while(!Heap && ((2*k)<=n)){ 
                int j = 2*k;
                if (j<n){
                    if(array[j-1]<array[j]) j =j+1;
                }
                if(v>=array[j-1]){
                    Heap=true;
                }
                else{
                    array[k-1]= array[j-1];  
                    k=j; 
                }                
            }//end while

            array[k-1]=v; 

        }//end for
        print(array);
        return(array);
    }

    static void print(int[]array){
        if(array==null){
            System.out.println("empty");
            return;
        }
        for(int i =0;i<array.length;i++){
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }//end print
}