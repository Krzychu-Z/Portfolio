#include<iostream>
#include "grapher.hpp"

using namespace std;

// int cspace[441] = { 0 };
// int* cPointer = &cspace[0];

void drawChart(int* spaceDrawer) {

	for (size_t i = 0; i < 441; i++) {

		//Switch to draw points on a chart. Makes new line by cases.
		switch (i) {
		case 20:
		case 41:
		case 62:
		case 83:
		case 104:
		case 125:
		case 146:
		case 167:
		case 188:
		case 209:
		case 230:
		case 251:
		case 272:
		case 293:
		case 314:
		case 335:
		case 356:
		case 377:
		case 398:
		case 419:
		case 440:
			if (*spaceDrawer) {
				cout << "@" << endl;
			}
			break;
		default:
			if (*spaceDrawer) {
				cout << "@";
			}
		}

		//Drawing axis and blank spaces
		switch (i) {
		case 10:
		case 31:
		case 52:
		case 73:
		case 94:
		case 115:
		case 136:
		case 157:
		case 178:
		case 199:
		    case 210:
			case 211:
			case 212:
			case 213:
			case 214:
			case 215:
			case 216:
			case 217:
			case 218:
			case 219:
			case 220:
			case 221:
			case 222:
			case 223:
			case 224:
			case 225:
			case 226:
			case 227:
			case 228:
			case 229:
		case 241:
		case 262:
		case 283:
		case 304:
		case 325:
		case 346:
		case 367:
		case 388:
		case 409:
		case 430:
			if(!*spaceDrawer){
				cout << "#";
			}
			break;
		case 230:
			if(!*spaceDrawer){
				cout << "#" << endl;
			}
			break;
		//Cases to be 'new lined'
		case 20:
		case 41:
		case 62:
		case 83:
		case 104:
		case 125:
		case 146:
		case 167:
		case 188:
		case 209:
		case 251:
		case 272:
		case 293:
		case 314:
		case 335:
		case 356:
		case 377:
		case 398:
		case 419:
		case 440:
			if(!*spaceDrawer){
				cout << " " << endl;
			}
			break;
		default:
			if(!*spaceDrawer){
				cout << " ";
			}
		}

		spaceDrawer++;
	
	}//for loop

	spaceDrawer -= 441;
}

void drawTrigChart(int* spaceDrawer){

	for (size_t i = 0; i < 2037; i++){

		//Switch to draw points.
		switch(i){
			//New line
			case 96:
			case 193:
			case 290:
			case 387:
			case 484:
			case 581:
			case 678:
			case 775:
			case 872:
			case 969:
			case 1066:
			case 1163:
			case 1260:
			case 1357:
			case 1454:
			case 1551:
			case 1648:
			case 1745:
			case 1842:
			case 1939:
			case 2036:
				if (*spaceDrawer) {
					cout << "@" << endl;
				}
				break;
			default:
				if (*spaceDrawer) {
					cout << "@";
				}
		}

		//Switch to draw axis and blank spaces
		switch(i){
			case 48:
				if(!*spaceDrawer){
					cout << "2";
				}
				break;
			case 145:
			case 242:
			case 339:
			case 436:
				if(!*spaceDrawer){
					cout << "#";
				}
				break;
			case 533:
				if(!*spaceDrawer){
					cout << "1";
				}
				break;
			case 630:
			case 727:
			case 824:
			case 921:
				case 970:
				case 971:
				case 972:
				case 973:
				case 974:
				case 975:
				case 976:
				case 977:
				case 978:
				case 979:
				case 980:
				case 981:
				case 982:
				case 983:
				case 984:
				case 985:
				case 986:
				case 987:
				case 988:
				case 989:
				case 990:
				case 991:
				case 992:
				case 993:
				case 994:
				case 995:
				case 996:
				case 997:
				case 998:
				case 999:
				case 1000:
				case 1001:
				case 1002:
				case 1003:
				case 1004:
				case 1005:
				case 1006:
				case 1007:
				case 1008:
				case 1009:
				case 1010:
				case 1011:
				case 1012:
				case 1013:
				case 1014:
				case 1015:
				case 1016:
				case 1017:
					if(!*spaceDrawer){
						cout << "#";
					}
					break;
				case 1018:
					if(!*spaceDrawer){
						cout << "0";
					}
					break;
				case 1019:
				case 1020:
				case 1021:
				case 1022:
				case 1023:
				case 1024:
				case 1025:
				case 1026:
				case 1027:
				case 1028:
				case 1029:
				case 1030:
				case 1031:
				case 1032:
				case 1033:
				case 1034:
				case 1035:
				case 1036:
				case 1037:
				case 1038:
				case 1039:
				case 1040:
				case 1041:
					if(!*spaceDrawer){
						cout << "#";
					}
					break;
				case 1042:
					if(!*spaceDrawer){
						cout << "2";
					}
					break;
				case 1043:
				case 1044:
				case 1045:
				case 1046:
				case 1047:
				case 1048:
				case 1049:
				case 1050:
				case 1051:
				case 1052:
				case 1053:
				case 1054:
				case 1055:
				case 1056:
				case 1057:
				case 1058:
				case 1059:
				case 1060:
				case 1061:
				case 1062:
				case 1063:
				case 1064:
				case 1065:
					if(!*spaceDrawer){
						cout << "#";
					}
					break;
				case 1066:
					if(!*spaceDrawer){
						cout << "4" << endl;
					}
					break;
			case 1115:
			case 1212:
			case 1309:
			case 1406:
			case 1503:
			case 1600:
			case 1697:
			case 1794:
			case 1891:
			case 1988:
				if(!*spaceDrawer){
					cout << "#";
				}
				break;
			case 96:
			case 193:
			case 290:
			case 387:
			case 484:
			case 581:
			case 678:
			case 775:
			case 872:
			case 969:
			case 1163:
			case 1260:
			case 1357:
			case 1454:
			case 1551:
			case 1648:
			case 1745:
			case 1842:
			case 1939:
			case 2036:
				if (!*spaceDrawer) {
					cout << " " << endl;
				}
				break;
			default:
				if (!*spaceDrawer) {
					cout << " ";
				}
		}//switch 2

		spaceDrawer++;

	}//for loop

	spaceDrawer -= 2037;
};

//int main() {

//	drawChart(cPointer);

//	return 0;
//}
