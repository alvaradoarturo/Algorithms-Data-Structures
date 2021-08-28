/*
    In an attempt to optimize my previous algorithm, I first compute whether or not the input is a valid cube
    root. This is because we know if a number is able to be created using the numbers raised to the power of three, than
    that number must also be a valid cube root number. Then we check whether the input minus values of A^3 results in a number
    that is a valid cube root. 
		Time Complexity: O(N^(1/3))		
*/
bool isCube(int c) {

    int cubeRoot = cbrtl(c);
    /*
    	If cube of cubeRoot is equals to c,
    	then it is perfect cube.
    */
    if (pow(cubeRoot,3) == c) {
        return true;
    }
    
    return false;
}


int countCubeSumPairs(int n) {

    // Counter counting the number of pairs of (a,b).
    int count = 0;
    // Finding the valid upper limit value of 'a'.
    int cubeRoot = cbrtl(n) + 1;
    // Iterating through all the possible values of 'a'.
    for (int a = 1; a <= cubeRoot; a++) {
        // Calculating value of 'a'^3.
        int a3 = pow(a,3);
        // Calculating 'n' - 'a'^3 which is the possible value of 'b'^3.
        int possibleB3 = n - a3;
        if (possibleB3 >= 0 && isCube(possibleB3)) {
            count += 1;
        }

    }

    return count;
}
