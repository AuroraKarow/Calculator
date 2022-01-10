#include "iostream"
#include "cct"

using namespace std;
using namespace cct;
using namespace stk;

int main(int argc, char *argv[], char *envp[])
{
    stack<double> ls_num;
    stack<char> ls_opr;

    bool flag = true;
    string eq = "", num_temp = "";
    cout << "[Equation] ";
    cin >> eq;
    
    for(auto i=0; i<eq.length(); ++i)
        if(eq[i] == ' ') continue;
        else if(eq[i]=='.' || is_num_syb(eq[i]))
        {   
            num_temp.push_back(eq[i]);
            if((i+1) == eq.length()) ls_num.push(std::atof(num_temp.c_str()));
        }
        else if(is_opr_syb(eq[i]))
        {
            if(eq[i] != '(')
            {
                auto curr_num = 0.0;
                if(num_temp.length())
                {
                    curr_num = std::atof(num_temp.c_str());
                    num_temp = "";
                }
                else if(ls_num.size() && (ls_opr.size()&&ls_opr.top()!='(')) curr_num = ls_num.pop();
                if(ls_opr.size() && ls_opr.top() != '(') 
                {
                    auto curr_syb = ' ';
                    curr_syb = ls_opr.top();
                    while(opr_pri(curr_syb)>(-1) && opr_pri(curr_syb)>=opr_pri(eq[i]))
                    {
                        curr_num = opr_ans(ls_num.pop(), curr_num, curr_syb);
                        ls_opr.pop();
                        if(ls_opr.size()) curr_syb = ls_opr.top();
                        else break;
                    }
                    if(curr_syb=='(' && eq[i]==')') ls_opr.pop();
                }
                ls_num.push(curr_num);
            }
            if((i+1) < eq.length() && eq[i]!=')') ls_opr.push(eq[i]);
        }
        else
        {
            break;
            flag = false;
        }

    auto ans = ls_num.pop();
    while(ls_num.size())
    {
        ans = opr_ans(ls_num.pop(), ans, ls_opr.pop());
        if(ans == NAN)
        {
            flag = false;
            break;
        }
    }
    if(ls_opr.size()) flag = false;
    if(flag) cout << "[Answer] " << ans << endl;
    else cout << "Illegal equation!" << endl;

    // 46,385,646,800.1 = (0-0.7+8*9/10*2^(7+3*8)*3-2)+6
    // 2.1080365201434976318052045030883 = .27+2.16-.8*.88^(.12+2*7/2)
    // -6.4578530930567937325022045146702 = -.7+.3-.4*3^(-2+.2*1.2)-6
    // -5.4962586387680569440780674730003 = -.7+(.3-.4*3)^(-2+.2*1.2)-6
    return EXIT_SUCCESS;
}