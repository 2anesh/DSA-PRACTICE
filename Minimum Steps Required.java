class Solution{
	int minSteps(String str) {
		//Write your code here
	// Get the length of the input string
    int n = str.length();
    // Initialize a counter variable to keep track of the number of changes
    int count = 0;
    // Initialize a variable to keep track of the previous character encountered
    char prev = '\0';
    // Loop through the string character by character
    for(int i=0; i<n; i++) {
        // Get the current character
        char ch = str.charAt(i);
        /*If the current character is different from the previous character, 
        increment the counter and update the previous character*/
        if(ch != prev) {
            count++;
            prev = ch;
        }
    }
    return count/2+1;
	}
}
