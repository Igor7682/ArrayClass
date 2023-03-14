#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdio.h>

class array
{
protected:

    std::string name = " ";

    const int max_size = 100;
    int real_size;

    int* arr = NULL;


public:
    array();
    array(int size);
    array(int size, std::string ob_name);
    array(int size, int val);
    array(const array& a);
    virtual ~array() 
    {
        delete[] arr;
    }

    virtual void arr_ent();
    void show();
    int size() const;
    virtual void change();
    virtual array sum(array& two);
    std::string get_name();
    virtual void operation(array two);

    virtual array& operator =(const array& two);
    int& operator[](int num) const;
};


class decimal :
    public array
{
    int sign;
    int* arr = NULL;

public:

    decimal();
    decimal(int size, int ob_sign, int val);
    decimal(int size);
    decimal(int size, std::string ob_name);
    decimal(const decimal& a);
    ~decimal() { delete[] arr; }

    void show();
    void arr_ent();
    int sign_check() const&;
    void sign_change(int new_sign);

    void change();
    decimal sum(const decimal& arr_two) const;
    decimal sub(const decimal& two) const;
    decimal mult(const decimal& two) const;
    int div(decimal& two);
    bool com(decimal& two);
    bool com_wo_sign(decimal& two) const;
    void operation(decimal& two);


    decimal& operator =(const decimal& two);
    decimal operator + (const decimal& two) const;
    decimal operator -(decimal& two);
    decimal operator *(decimal& two);
    int operator /(decimal two);
    bool operator >(decimal two);
    bool operator >(int num);
    bool operator <(decimal two);
    bool operator <(int num);
    int& operator[](int num) const { return arr[num]; };
};

class BitString :
    public array
{

    int* arr = NULL;
public:

    BitString(int size);
    BitString(int size, std::string name);
    BitString(int size, int val);
    BitString(const BitString& two);
    ~BitString() { delete[] arr; }

    void change();
    void arr_ent();
    void show();
    BitString sum(BitString& two);
    BitString bit_and(BitString& two);
    BitString bit_xor(BitString& two);
    BitString bit_not();

    BitString& operator =(const BitString& two);

    void operation(BitString& two);
    int& operator[](int num) const { 
        if (num > -1 && num < real_size) {
            return arr[num];
        };
};

void menu(int op, array& Array1, array& Array2, decimal& Decimal1, decimal& Decimal2, BitString& BitString1, BitString& BitString2);

int main()
{

    int size = 0;
    int op;

    std::cin >> size;

    array Array1(size, "Array1");
    Array1.arr_ent();

    array Array2(size, "Array2");
    Array2.arr_ent();

    Array1.show();
    Array2.show();

    std::cin >> size;

    decimal Decimal1(size, "Decimal1");
    Decimal1.arr_ent();

    decimal Decimal2(size, "Decimal2");
    Decimal2.arr_ent();


    Array1.operation(Array2);

    Decimal1.show();
    Decimal2.show();


    Decimal1.operation(Decimal2);

    std::cin >> size;

    BitString BitString1(size, "BitString1");
    BitString1.arr_ent();

    BitString BitString2(size, "BitString2");
    BitString2.arr_ent();

    BitString1.show();
    BitString2.show();

    BitString1.operation(BitString2);

    do
    {
        std::cin >> op;
        menu(op, Array1, Array2, Decimal1, Decimal2, BitString1, BitString2);

    } while (op != 0);

    return 0;
}



void menu(int op, array& Array1, array& Array2, decimal& Decimal1, decimal& Decimal2,
    BitString& BitString1, BitString& BitString2)
{

    switch (op) {

    case 1:
        Array1.change();
        Array1.show();
        Array2.show();
        Array1.operation(Array2);
        break;
    case 2:
        Array2.change();
        Array1.show();
        Array2.show();
        Array1.operation(Array2);
        break;
    case 3:
        Decimal1.change();
        Decimal1.show();
        Decimal2.show();
        Decimal1.operation(Decimal2);
        break;
    case 4:
        Decimal2.change();
        Decimal1.show();
        Decimal2.show();
        Decimal1.operation(Decimal2);
        break;
    case 5:
        BitString1.change();
        BitString1.show();
        BitString2.show();
        BitString1.operation(BitString2);
        break;
    case  6:
        BitString2.change();
        BitString1.show();
        BitString2.show();
        BitString1.operation(BitString2);
        break;
    default:
        break;
    }
}


array::array(int size)
{
    real_size = size;
    arr = new int[real_size];
   
}
array::array(int size, std::string ob_name)
{
    name = ob_name;
    real_size = size;
    arr = new int[real_size];
    
}
array::array()
{
    real_size = max_size;
    arr = new int[real_size];
    
}
array::array(int size, int val)
{
    real_size = size;
    arr = new int[real_size];
   
    for (int i = 0; i < real_size; i++)
    {
        arr[i] = 0;
    }
}

array::array(const array& a)
{
    real_size = a.size();
    arr = new int[real_size];

    for (int i = 0; i < real_size; i++)
    {
        arr[i] = a[i];
    }
};


void array::arr_ent()
{
    for (int i = 0; i < real_size; i++)
    {
        std::cin >> arr[i];

    }

}
int array::size() const
{
    return real_size;

}


void array::change()
{
    int num = 0;
    int val = 0;
    std::cin >> num >> val;
    arr[num] = val;
    std::cout << std::endl;
}

int& array:: operator[](int num) const
{
    return arr[num];
}

void array::show()
{
    std::cout << name << " ";

    for (int i = 0; i < real_size; i++)
    {
        std::cout << arr[i] << "  ";
    }

}

array array::sum(array& two)
{


    array rez(real_size);

    for (int i = 0; i < real_size; i++)
    {
        rez[i] = arr[i] + two[i];
    }
    return rez;
}

array& array::operator =(const array& two)
{
    if (this == &two) {
        return *this;
    }

    delete[] arr;

    real_size = two.size();

    arr = new int[real_size];

    for (int i = 0; i < two.size(); i++)
    {
        arr[i] = two[i];
    }
    return *this;
}

void array::operation(array two)
{
    array rez(sum(two));


    std::cout << std::endl << name << "+" << two.get_name() << "  ";
    rez.show();
    std::cout << std::endl;
}







decimal::decimal()
{
    std::cin >> sign;
}
decimal::decimal(int size, int ob_sign, int val)
{
   
    real_size = size;
    arr = new int[real_size];
    for (int i = 0; i < real_size; i++)
    {
        arr[i] = val;
    }
    sign = ob_sign;

}
decimal::decimal(int size, std::string ob_name)
{
    name = ob_name;
    real_size = size;
    arr = new int[real_size];
}
decimal::decimal(int size)
{
    std::cin >> sign;
}

decimal::decimal(const decimal& a)
{
    real_size = a.size();
    arr = new int[real_size];

    for (int i = 0; i < real_size; i++)
    {
        arr[i] = a[i];
    }
    sign = a.sign_check();
}


decimal& decimal::operator=(const decimal& two)
{
    
    if (this == &two) {
        return *this;
    }

    if (real_size > 0) {
        delete[] arr;
    }

    real_size = two.size();
    arr = new int[real_size];
    for (int i = 0; i < real_size; i++)
    {
        arr[i] = two[i];
    }
   
    sign = two.sign_check();
    return *this;
}
decimal decimal::operator + (const decimal& two) const
{

    if (two.sign_check() > 0)
    {
        
        return sum(two);
    }
    else
    {
        return sub(two);
    }
}
decimal decimal::operator -(decimal& two)
{
    if (two.sign_check() > 0)
    {
        return sub(two);
    }
    else
    {
        return sum(two);
    }
}
decimal decimal::operator *(decimal& two)
{
    return mult(two);
}
int decimal::operator /(decimal two)
{
    return div(two);
}

bool decimal::operator >(decimal two)
{
    if (com(two) == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool decimal::operator>(int num)
{

    if (sign > 0)
    {
        return true;
    }
    else
    {

        return false;
    }


}
bool decimal::operator <(decimal two)
{
    if (com(two) == true)
    {
        return false;
    }
    else
    {
        return true;
    }

}
bool decimal::operator <(int num)
{

    if (sign > 0)
    {
        return false;
    }
    else
    {

        return true;
    }

}

bool decimal::operator ==(int num) const
{
    for (int i = real_size - 1; i > -1; i--)
    {
        if (arr[i] != num % 10)
        {
            return false;
        }


        num / 10;
    }
    return true;


}


void decimal::arr_ent()
{
    for (int i = real_size - 1; i > -1; i--)
    {
        std::cin >> arr[i];

    }

}
void decimal::show()
{
    int i = 0;

    std::cout << name << " ";

    if (sign < 0)
    {
        std::cout << "-";
    }

    for(i = 0; i < real_size; i++)
    {
        if (arr[i] != 0)
        {
            break;
        }
        if (i == real_size - 1)
        {
            i = 0;
            break;
        }
    }
    for (i; i < real_size; i++)
    {
        std::cout << arr[i];

    }
    std::cout << " ";

}
void decimal::change()
{

    for (int i = real_size - 1; i > -1; i--)
    {
        std::cin >> arr[i];
    }

}
void decimal::sign_change(int new_sign)
{
    sign = new_sign;
}
int decimal::sign_check() const&
{
    return sign;
}
std::string array::get_name()
{

    return name;
}


decimal decimal::sum(const decimal& arr_two) const
{
    int n3 = real_size - 1;
    int t = 0;
    decimal rez(real_size, 0, 0);

    for (int i = n3, q = n3, e = q; i > -1; i--, q--, e--)
    {
        t = arr[q] + arr_two[e];
        if (i == 0 && t > 9)
        {
            rez[i] += 10 + (t - 10);
        }
        else {
            if (t > 9)
            {
                rez[i] += t - 10;
                rez[i - 1] += 1;

            }
            else
            {
                rez[i] += t;
            }
        }

        for (int i = n3; i > 0; i--)
        {

            if (rez[i] > 9)
            {
                rez[i] = rez[i] - 10;
                rez[i - 1] += 1;
            }
        }

    }
    return rez;
}
decimal decimal::sub(const decimal& arr_two) const
{
    int n3 = real_size - 1;
    decimal one(n3 + 1, 1, 0);
    decimal two(n3 + 1, 1, 0);
    decimal rez(n3 + 1, 1, 0);
    int t = 0;
    one = *this;
    two = arr_two;
    if (com_wo_sign(two) == true)
    {
        for (int i = n3, q = n3, e = q; i > -1; i--, q--, e--)
        {
            t = one[q] - two[e];
            if (t < 0)
            {
                rez[i] += 10 - t * -1;
                one[i - 1] -= 1;
            }
            else
            {
                rez[i] += t;
            }
        }
        for (int i = n3; i > -1; i--)
        {

            if (rez[i] < 0)
            {
                rez[i] += 10 - rez[i] * -1;
                rez[i - 1] -= 1;
            }
        }
    }
    else
    {
        rez.sign_change(-1);
        for (int i = n3, q = n3, e = q; i > -1; i--, q--, e--)
        {
            t = two[q] - one[e];
            if (t < 0)
            {
                rez[i] += 10 - t * -1;
                two[i - 1] -= 1;
            }
            else
            {
                rez[i] += t;
            }
        }
        for (int i = n3; i > -1; i--)
        {
            if (rez[i] < 0)
            {
                rez[i] += 10 - rez[i] * -1;
                rez[i - 1] -= 1;
            }


        }
    }
    return rez;
}
decimal decimal::mult(const decimal& two) const
{
    int n = real_size;
    int n1 = n * 2;
    int n2 = n1 - 1;

    decimal rez(n1, 1, 0);
    decimal t1(n1, 0, 0);
    int t = 0;
    if (two == 0) 
    {
        decimal zero(1, 1, 0);
        return zero;
    }
    else
    {
        if (sign < 0 || two.sign < 0)
        {
            rez.sign_change(-1);
        }
        for (int q = n - 1; q > -1; q--)
        {
            for (int i = n + 2, r = n - 1; r > -1; i--, r--)
            {
                if (two[q] == 1 || arr[r] == 1)
                {
                    t = arr[r] * two[q];
                    t1[i] += t;
                    if (t1[i] > 9)
                    {
                        t1[i] = t1[i] - 10;
                        t1[i - 1] += 1;
                    }
                }
                else
                {
                    t = arr[r] * two[q];
                    t1[i] += t % 10;
                    t1[i - 1] += t / 10;
                    if (t1[i] > 9)
                    {
                        t1[i] = t1[i] - 10;
                        t1[i - 1] += 1;
                    }

                }
            }
            for (int i = n2, w = n + 2; w > -1; i--, w--)
            {
                rez[i] += t1[w];
            }
            for (int i = n1 - 1; i > -1; i--)
            {
                if (rez[i] > 9)
                {
                    rez[i] = rez[i] - 10;
                    rez[i - 1] += 1;
                }
            }
            n2--;
            for (int i = 0; i < n1; i++)
            {
                t1[i] = 0;
            }
            t = 0;
        }
        return rez;
    }
}
int decimal::div( decimal& two)
{


    if (two == 0)
    {
        throw "Division by 0";
    }
    else
    {
        int rez = 0;
        bool sign1 = false;
        bool sign2 = false;

        sign = 1;
        two.sign_change(1);
        decimal temp = *this;
        if (com_wo_sign(two) == false)
        {
            return  rez;
        }
        else
        {
            do {
                temp = temp - two;
                if (temp > 0)
                {
                    rez++;
                }

            } while (temp > 0);


            return rez;
        }
    }
}


bool decimal::com(decimal& two)
{
    if (sign == two.sign_check())
    {
        if (real_size > two.size())
        {
            return true;
        }
        else
        {
            if (real_size == two.size())
            {
                for (int i = 0; i < real_size; i++)
                {
                    if (arr[i] > two[i])
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        if (sign > two.sign_check())
        {
            return true;

        }
        else
        {
            return false;
        }
    }
}
bool decimal::com_wo_sign(decimal& two) const
{
    if (real_size > two.size())
    {
        return true;
    }
    else
    {
        if (real_size == two.size())
        {
            for (int i = 0; i < real_size; i++)
            {
                if (arr[i] != two[i])
                {
                    if (arr[i] > two[i])
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            return false;
        }
    }
    return false;
}

void decimal::operation(decimal& two)
{
    try {
        std::cout << std::endl << name << "+" << two.get_name() << "  ";
        (*this + two).show();
        std::cout << std::endl << name << "-" << two.get_name() << "  ";
        (*this - two).show();
        std::cout << std::endl << name << "*" << two.get_name() << "  ";
        (*this * two).show();
        std::cout << std::endl << name << "/" << two.get_name() << "  "
            << *this / two << std::endl;
    }
    catch (const char* ex)
    {
        std::cout << std::endl << ex << std::endl;
    }
}


BitString::BitString(int size)
{
    real_size = size;
    arr = new int[real_size];
}
BitString::BitString(int size, std::string ob_name)
{
    name = ob_name;
    real_size = size;
    arr = new int[real_size];
    for (int i = 0; i < real_size; i++)
    {
        arr[i] = 0;
    }
}
BitString::BitString(int size, int val)
{
    real_size = size;
    arr = new int[real_size];
    for (int i = 0; i < real_size; i++)
    {
        arr[i] = val;
    }
}

BitString::BitString(const BitString& a)
{
    real_size = a.size();
    arr = new int[real_size];
    for (int i = 0; i < a.size(); i++)
    {
        arr[i] = a[i];
    }
}






BitString BitString::sum(BitString& two)
{

    BitString rez(real_size, 0);

    for (int i = 0; i < real_size; i++)
    {
        if (arr[i] == 1 || two[i] == 1)
        {
            rez[i] = 1;
        }

    }
    return rez;
}
BitString BitString::bit_and(BitString& two)
{

    BitString rez(real_size, 1);

    for (int i = 0; i < real_size; i++)
    {
        if (arr[i] == 0 || two[i] == 0)
        {
            rez[i] = 0;
        }

    }
    return rez;
}
BitString BitString::bit_xor(BitString& two)
{

    BitString rez(real_size, 1);

    for (int i = 0; i < real_size; i++)
    {
        if (arr[i] == two[i])
        {
            rez[i] = 0;
        }

    }
    return rez;
}
BitString BitString::bit_not()
{

    BitString rez(real_size, 1);

    for (int i = 0; i < real_size; i++)
    {
        if (arr[i] == 1)
        {
            rez[i] = 0;
        }

    }
    return rez;
}



BitString& BitString::operator =(const BitString& two)
{
    if (this == &two) {
        return *this;
    }

    if (real_size > 0) {
        delete[] arr;
    }

    real_size = two.size();
    arr = new int[real_size];
    for (int i = 0; i < two.size(); i++)
    {
        arr[i] = two[i];
    }
    return *this;

}

void BitString::operation(BitString& two)
{

    std::cout << std::endl << name << " & " << two.get_name() << "  ";
    bit_and(two).show();
    std::cout << std::endl << name << " ! " << two.get_name() << "  ";
    sum(two).show();
    std::cout << std::endl << name << " ^ " << two.get_name() << "  ";
    bit_xor(two).show();
    std::cout << std::endl << " ! " << name << "  ";
    bit_not().show();
    std::cout << " ! " << two.get_name() << "  ";
    (two.bit_not()).show();
    std::cout << std::endl;
}


void BitString::change()
{
    for (int i = 0; i < real_size; i++)
    {
        std::cin >> arr[i];

    }

}

void BitString::arr_ent()
{
    for (int i = 0; i < real_size; i++)
    {
        std::cin >> arr[i];

    }
}
void BitString::show()
{
    std::cout << name << " ";

    for (int i = 0; i < real_size; i++)
    {
        std::cout << arr[i];
    }
    std::cout << " ";
}
