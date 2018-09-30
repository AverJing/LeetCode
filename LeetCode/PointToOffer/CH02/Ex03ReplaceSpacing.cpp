/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>

class Solution {
public:
	/*
	void replaceSpace(char *str, int length) {
		if (!str && length <= 0)
			return;

		int count = 0;
	    int i = 0
		for (; str[i] != '\0'; ++i) {
			if (str[i] == ' ') ++count;
		}
		--i;  //array length
		int newLength = i + 2 * count;

		if (newLength > length) return;

		int indexOri = i;
		int indexNew = newLength;
		str[indexNew+1] = '\0';
		while (indexOri >= 0 && indexNew > indexOri) {
			if (str[indexOri] == ' ') {
				str[indexNew--] = '0';
				str[indexNew--] = '2';
				str[indexNew--] = '%';
			}
			else {
				str[indexNew--] = str[indexOri];
			}
			--indexOri;
		}
	}
	*/
};

int main(){
	
}	