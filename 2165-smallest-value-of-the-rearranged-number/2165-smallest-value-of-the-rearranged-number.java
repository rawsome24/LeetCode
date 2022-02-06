class Solution {
    public long smallestNumber(long num) {
        // convert the number into a string
    
    String str;
    
    if(num < 0)
    {
        long nums = num*(-1);
        str = String.valueOf(nums);
    }
    else
    {
        str = String.valueOf(num);
    }
    
    char arr[] = str.toCharArray();
    
    long ans;
    
    if(num < 0) //negative
    {
        //sort the character array in descending
        // with 0 
        
        Arrays.sort(arr);   // from this we will get the ascending order, but we need the opposite of it
        reverse(arr);
        
        String res = String.valueOf(arr);   //converting the charcter array back to string
        ans = Long.parseLong(res); //converting string to the long value 
        ans = -ans;
    }
    else
    {
        //if the number is positive
        Arrays.sort(arr);
        
        //Here, we will have 0 in the front so, we have to swap it with the first non-zero element in the array    
        int i=0;
        
        for(i = 0;i<arr.length;i++)
        {
            if(arr[i] != '0')
            {
                //we get the last i value where the 0 starts
                break;
            }
        }
        
        if(i <= (arr.length-1)) //if there is an 0 in the array
        {
            char temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
        }
        
        String res = String.valueOf(arr);   //converting the charcter array back to string
        ans = Long.parseLong(res); //converting string to the long value 
        
    }
    
    return ans;
}

public void reverse(char[] arr)
{
    // we will traverse half of the array and will put all the element of the first half, in the last one.
    // in simle words 1st element as last, 2nd element as 2nd last ....
    
    int len = arr.length;
    
    for(int i=0;i<arr.length/2;i++)
    {
        char temp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = temp;
    }

    }
}