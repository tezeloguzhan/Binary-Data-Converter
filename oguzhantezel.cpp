#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>

vi binary;

void sign_Integer()
{
    if(binary[binary.size()-1]==0)
    {
        int sum=0;
        for(int i=0; i<binary.size(); i++)
        {
            sum+=binary[i]*pow(2,i);
        }
        cout<<sum<<endl;
    }
    else
    {
        for(int i=0;i<binary.size();i++)
        {
            if(binary[i]==0)
                binary[i]=1;
            else
                binary[i]=0;
        }
        int carry=1;
        for(int i=0;i<binary.size();i++)
        {
            int aaa=carry+binary[i];
            if(aaa==2)
            {
                binary[i]=0;
                carry=1;
            }
            else if(aaa=1)
            {
                binary[i]=1;
                carry=0;
            }
            else
                carry=0;
        }
        int sum=0;
        for(int i=0; i<binary.size(); i++)
        {
            sum+=binary[i]*pow(2,i);
        }
        cout<<"-"<<sum<<endl;
    }
}

void Unsign_Integer()
{
    int sum=0;
    for(int i=0; i<binary.size(); i++)
    {
        sum+=binary[i]*pow(2,i);
    }
    cout<<sum<<endl;
}

void Floating_Number()
{
    int sign_bit=binary[binary.size()-1];
    int byte=binary.size()/8;
    int bias;
    if(byte==1)
    {
        bias=4;
    }
    else if(byte==2)
    {
        bias=6;
    }
    else if(byte==3)
    {
        bias=8;
    }
    else if(byte==4)
    {
        bias=10;
    }
    int bias_value=pow(2,(bias-1))-1;
    int exp=0,exp_value=1;
    int j=0;
    for(int i=binary.size()-(bias+1); i<binary.size()-1; i++)
    {
        exp+=binary[i]*pow(2,j++);
        if(binary[i]==0)
            exp_value=0;
    }
    vi mantisa;
    if(byte==3||byte==4)
    {
        int res=0;
        for(int i=binary.size()-(bias+2); i>=binary.size()-(bias+14); i--)
        {
            mantisa.push_back(binary[i]);

        }
        if(binary[binary.size()-(bias+15)]==1)
        {
            int ckk=0;
            for(int i=binary.size()-(bias+16); i>=0; i--)
            {
                if(binary[i]==1)
                    ckk=1;
            }
            if(ckk==1)
            {
                mantisa[mantisa.size()-1]=1;
            }
            else
            {
                if(mantisa[mantisa.size()-1]==1)
                {
                    int carr=1;
                    for(int i=0; i<mantisa.size(); i++)
                    {
                        int aaa=carr+mantisa[i];
                        if(aaa==2)
                        {
                            mantisa[i]=0;
                            carr=1;
                        }
                        else if(aaa==1)
                        {
                            mantisa[i]=1;
                            carr=0;
                        }
                        else
                            carr=0;
                    }
                    if(carr==1)
                        res=1;
                }
            }

        }
        double manti=res;
        for(int i=0; i<mantisa.size(); i++)
        {
            manti+=(mantisa[i]*(1/pow(2,i+1)));
        }
        if(exp_value==1)
        {
            if(manti==0)
            {
                if(sign_bit==1)
                    cout<<"-∞"<<endl;
                else
                    cout<<"+∞"<<endl;
            }
            else
            {
                cout<<"NaN"<<endl;
            }
        }
        else if(exp==0)
        {
            if(manti==0)
            {
                if(sign_bit==0)
                    cout<<"+0"<<endl;
                else
                    cout<<"-0"<<endl;
            }
            else
            {
                double result = pow(-1,sign_bit)*(manti)*pow(2,((exp+1)-bias_value));
                cout<<result<<endl;
            }
        }
        else
        {
            double result = pow(-1,sign_bit)*(1+manti)*pow(2,((exp)-bias_value));
            cout<<result<<endl;
        }

    }
    else
    {
        for(int i=binary.size()-(bias+2); i>=0; i--)
        {
            mantisa.push_back(binary[i]);

        }
        double manti=0;
        for(int i=0; i<mantisa.size(); i++)
        {
            manti+=(mantisa[i]*(1/pow(2,i+1)));
        }
        if(exp_value==1)
        {
            if(manti==0)
            {
                if(sign_bit==1)
                    cout<<"-∞"<<endl;
                else
                    cout<<"+∞"<<endl;
            }
            else
            {
                cout<<"NaN"<<endl;
            }
        }
        else if(exp==0)
        {
            if(manti==0)
            {
                if(sign_bit==0)
                    cout<<"+0"<<endl;
                else
                    cout<<"-0"<<endl;
            }
            else
            {
                double result = pow(-1,sign_bit)*(manti)*pow(2,((exp+1)-bias_value));
                cout<<result<<endl;
            }
        }
        else
        {
            double result = pow(-1,sign_bit)*(1+manti)*pow(2,((exp)-bias_value));
            cout<<result<<endl;
        }
    }

}

int main()
{
    string s;
    cout<<"Enter hexadecimal number(A-F and 0-9 accept): ";
    cin>>s;
    cout<<endl;
    char type;
    cout<<"Enter Data type:";
    cin>>type;
    cout<<endl;
    int len= s.length();
    if(len>8)
        cout<<"It is more than 4 byte"<<endl;
    else
    {
        if(type=='S')
        {
            int ck=0;
            for(int i=len-1; i>=0; i--)
            {
                int p;
                if(s[i]>='A'&&s[i]<='F')
                {
                    p=10+(s[i]-'A');
                }
                else if(s[i]>='0'&&s[i]<='9')
                {
                    p=s[i]-'0';
                }
                else
                    ck=1;
                for(int j=0; j<4; j++)
                {
                    if(p%2==1)
                    {
                        binary.push_back(1);
                    }
                    else
                    {
                        binary.push_back(0);
                    }

                    p=p/2;
                }
            }

            if(len%2==1)
            {
                for(int i=0; i<4; i++)
                {
                    binary.push_back(0);
                }
            }

            if(ck==1)
                cout<<"Please Enter Hexadecimal Number"<<endl;
            else
                sign_Integer();
        }

        else if(type=='U')
        {
            int ck=0;
            for(int i=len-1; i>=0; i--)
            {
                int p;
                if(s[i]>='A'&&s[i]<='F')
                {
                    p=10+(s[i]-'A');
                }
                else if(s[i]>='0'&&s[i]<='9')
                {
                    p=s[i]-'0';
                }
                else
                    ck=1;
                for(int j=0; j<4; j++)
                {
                    if(p%2==1)
                    {
                        binary.push_back(1);
                    }
                    else
                    {
                        binary.push_back(0);
                    }

                    p=p/2;
                }
            }

            if(len%2==1)
            {
                for(int i=0; i<4; i++)
                {
                    binary.push_back(0);
                }
            }

            if(ck==1)
                cout<<"Please Enter Hexadecimal Number"<<endl;
            else
                Unsign_Integer();
        }

        else if(type=='F')
        {
            int ck=0;
            for(int i=len-1; i>=0; i--)
            {
                int p;
                if(s[i]>='A'&&s[i]<='F')
                {
                    p=10+(s[i]-'A');
                }
                else if(s[i]>='0'&&s[i]<='9')
                {
                    p=s[i]-'0';
                }
                else
                    ck=1;
                for(int j=0; j<4; j++)
                {
                    if(p%2==1)
                    {
                        binary.push_back(1);
                    }
                    else
                    {
                        binary.push_back(0);
                    }

                    p=p/2;
                }
            }

            if(len%2==1)
            {
                for(int i=0; i<4; i++)
                {
                    binary.push_back(0);
                }
            }

            if(ck==1)
                cout<<"Please Enter Hexadecimal Number"<<endl;
            else
                Floating_Number();


        }

    }
    return 0;
}

