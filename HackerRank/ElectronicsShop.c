int getMoneySpent(int keyboards_count, int* keyboards, int drives_count, int* drives, int b) {
    /*
     * Write your code here.
     */
     int max = -1;
     int temp = 0;
     for(int k_i = 0 ; k_i < keyboards_count; k_i++) {
         for(int d_i = 0 ; d_i<drives_count; d_i++)
         {
             temp = ((*(keyboards+k_i))+(*(drives+d_i)));
             if((temp >= max) && (temp <= b))
             {
                 max = temp;
             }
         }
     
     }
    return max;
}