CCT_BEGIN

bool is_num_syb(char syb) { return (syb>='0'&&syb<='9'); }

bool is_cal_syb(char syb) { return (syb=='+' || syb=='-' || syb=='*' || syb=='/' || syb=='^'); }

bool is_opr_syb(char syb) { return (is_cal_syb(syb) || syb=='(' || syb==')'); }

int opr_pri(char syb)
{
    switch (syb)
    {
    case '+': return PRI_ADD;
    case '-': return PRI_SUB;
    case '*': return PRI_MUL;
    case '/': return PRI_DIV;
    case '^': return PRI_POW;
    default: return -1;
    }
}

double opr_ans(double left, double right, char syb)
{
    switch (syb)
    {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/': return left / right;
    case '^': return std::pow(left, right);
    default: return NAN;
    }
}

CCT_END