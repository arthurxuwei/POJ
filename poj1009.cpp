#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define size 1005
using namespace std;
struct pix {
	int pos;
	int code;
}outmap[size*8];


int inmap[size][2];
int width, cntp, tot;

int cmp(pix x, pix y) {
	return x.pos < y.pos;
}

int getnum(int pos) {
	int p =0,i=0;
	while(p<pos)
		p+=inmap[i++][1];

	return inmap[i-1][0];
}

int getcode(int pos, int row, int col) {
	int num = getnum(pos), ret=0;


	for (int i = row-1; i <= row+1; ++i)
		for (int j = col-1; j <= col+1; ++j) {
			int tpos= i*width+j+1;
			if( i<0 || j<0 || j>=width || tpos >= tot || tpos == pos)
				continue;

			int tmp = getnum(tpos);
			if(abs(tmp-num)>ret) ret = abs(tmp-num);
		}
	return ret;
}

int main() {
	while ( cin >> width && width) {
		int num, len;
		cntp=tot=0;
		while( cin >> num >> len && num) {
			inmap[cntp][0]=num;
			inmap[cntp++][1]=len;
			tot+=len;
		}
		cout << width << endl;

		int pos=1,k=0;
		for (int p=0; p<= cntp; p++) {
			int row = (pos-1) / width;
			int col = (pos-1) % width;
			
			if(col == width-1) {
				if ((row+2)*width <tot) {
					outmap[k].pos = pos+width;
					outmap[k++].code = getcode(pos+width+1, row+2, 0);
				}
			}
			
			for(int i=row-1; i <= row+1; i++) {
				for(int j=col-1; j <= col+1; j++) {
					int tpos = i*width + j+1;
					if (i<0 || j<0 || j>=width ||tpos >= tot)
						continue;

					outmap[k].pos = tpos-1;
					outmap[k++].code = getcode(tpos, i, j);
				}
			}
			pos+=inmap[p][1];
		}

		sort(outmap, outmap+k, cmp);

		pix tmp=outmap[0];
		for (int i=0; i<k; ++i) {
			if (outmap[i].code == tmp.code)
				continue;

			cout << tmp.code << ' ' << outmap[i].pos-tmp.pos <<endl;
			tmp = outmap[i];
		}

		cout << tmp.code << ' ' << tot-tmp.pos+1 <<endl;
		cout << "0 0"  << endl;
	}
	cout << "0" << endl;
}
/* this is correct answer.
#include <iostream>  
#include <algorithm>  
#include <vector>  
  
using namespace std;  
  
typedef class Point  
{  
public:  
    int iFirst;  
    int iSecond;  
  
    Point(int iF, int iS): iFirst(iF), iSecond(iS){};  
}Pix, Pair;  
  
vector<Pair> vMap;  
vector<Pix> vResultMap;  
  
int iWid;  
int iPairV;  
int iPairC;  
int iTotal = 0;  
  
void calculateMap();  
int getCode(int iPos, int iRow, int iCol);  
int getValue(int iPos);  
int cmp(const void *pL, const void *pR);  
  
int main ()  
{  
    // 读入map且不为0  
    while ((cin>> iWid) && iWid)  
    {  
        // 读入一组数据且不同时为0  
        while ((cin>> iPairV >> iPairC) && (iPairV || iPairC))  
        {  
            iTotal += iPairC;  
            Pair tmpPair(iPairV, iPairC);  
            vMap.push_back(tmpPair);  
        }  
  
        cout <<iWid<<endl;  
  
        calculateMap();  
  
        qsort(&vResultMap[0], vResultMap.size(), sizeof(Pix), cmp);  
  
        int iCur = 0;  
        int iSize = vResultMap.size();  
        for(int i=0;i<iSize;i++)  
        {  
            if(vResultMap[iCur].iSecond == vResultMap[i].iSecond)  
            {  
                continue;  
            }  
  
            cout << vResultMap[iCur].iSecond << " " << vResultMap[i].iFirst - vResultMap[iCur].iFirst << endl;  
            iCur = i;  
        }  
        cout << vResultMap[iCur].iSecond << " " << iTotal - vResultMap[iCur].iFirst << endl;  
        cout<<"0 0"<<endl;  
  
        // 准备下一张MAP  
        vMap.clear();  
        vResultMap.clear();  
        iTotal = 0;  
    }  
  
    cout <<"0"<< endl;  
  
    return 0;  
}  
  
void calculateMap()  
{  
    int iPairPos = 1;  
  
    for (int iMap = 0; iMap <= vMap.size(); iMap ++)  
    {  
        int iRow = (iPairPos - 1)/iWid;  
        int iCol = (iPairPos - 1)%iWid;  
  
        // 此处处理1号点问题  
        if (iCol == iWid - 1)  
        {  
            if ((iRow + 2)*iWid < iTotal)  
            {  
                Pix tmpPix(iPairPos + iWid, getCode(iPairPos + iWid + 1, iRow + 2, 0));  
                vResultMap.push_back(tmpPix);  
            }  
        }  
  
        for (int i = iRow - 1; i <= iRow + 1; i ++)  
        {  
            for (int j = iCol - 1; j <= iCol + 1; j ++)  
            {  
                int iPos = iWid*i+j+1;  
  
                if (i <0 || j <0 || iPos > iTotal || j >= iWid )  
                {  
                    continue;  
                }  
  
                Pix tmpPix(iWid*i+j, getCode(iPos, i, j));  
                vResultMap.push_back(tmpPix);  
            }  
        }  
  
        iPairPos += vMap[iMap].iSecond;  
    }  
}  
  
int getCode(int iPos, int iRow, int iCol)  
{  
    int iMid = getValue(iPos);  
    int r = 0;  
  
    for (int i = iRow -1; i <= iRow + 1; i++)  
    {  
        for (int j = iCol - 1; j <= iCol + 1; j++)  
        {  
            int iTmpPos = iWid*i+j+1;  
            if (iTmpPos == iPos || i < 0 || j < 0 || j >= iWid || iTmpPos > iTotal)  
            {  
                continue;  
            }  
  
            int iTmp = getValue(iTmpPos);  
            if (abs(iMid - iTmp) > r)  
            {  
                r = abs(iTmp - iMid);  
            }  
        }  
    }  
    return r;  
}  
  
int getValue(int iPos)  
{  
    int iN = 0;  
  
    int i;  
    for (i = 0; iN < iPos; i ++)  
    {  
        iN += vMap[i].iSecond;  
    }  
  
    return vMap[i - 1].iFirst;  
}  
  
int cmp(const void *pL, const void *pR)  
{  
    Pix *pPixL = (Pix *)pL;  
    Pix *pPixR = (Pix *)pR;  
  
    return pPixL->iFirst - pPixR->iFirst;  
}  */
