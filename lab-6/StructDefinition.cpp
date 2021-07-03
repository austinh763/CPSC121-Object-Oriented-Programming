//Either: 1. Rename and expand this file 2. Delete this file 3. Leave it untouched

struct Calculator {
	long long LHValue;//The first value is simply a large integer variable. This is also where the answer to an equation is stored.
//The second value is a POINTER to a large integer. We will be able to use it similarly after syntax differences.
//To use it, we will need to assign it memory space (using a variables address or, ideally, with the "new" keyword)
	long long * RHValue;//If the user provides only the = operator, the previous RHValue and operator will be used
	char lastOperator;//Indicates which operator was last used, in case one isn't provided
};
