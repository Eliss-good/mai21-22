
int strConteins(char *a, char *str){

	int returnValue = -1;

	for(int i = 0; str[i] != '\0'; ++i){

		if(a[0] == str[i]){
			
			bool setupValue = true;
			int j = 0;
			while(a[j] != '\0'){
				
				if(a[j] != str[i+j]) {
					setupValue = false;
					break;
				}

				j++;
			} 

			if(setupValue){
				returnValue = i;
			}

			break;
		}

	}

	return reternValue;
}
