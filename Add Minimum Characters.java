class Solution
{
	public static int addMinChar(String str){
		//code here

		    //check for the max palindrome string starting from the 0th index
		    int i;
		    int j = 1; 
		    int maxLength = 0;
		    int copyJ = j;
		    while(j<str.length()){
	            i=0;
	            copyJ = j;
		        while(i<j){
		            if(str.charAt(i)!=str.charAt(j)){
		                break;
		            }
		            j--;
		            i++;
		        }
		        if(i>=j){
		            //Palindrome was found, hence calculate length
		            maxLength = Math.max(copyJ+1,maxLength);
		        }
		        
		        j = copyJ + 1;
		    }
		    
		    if(maxLength==0){
		        return str.length()-1;
		    }
		    else {
		        return (str.length()-maxLength);
		    }

	}
}
