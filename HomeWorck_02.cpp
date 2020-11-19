#include <iostream>
#include <cmath>

bool getContinueTheProgram() {

	std::string Answer;
	std::cin >> Answer;

    if((Answer == "YES")||(Answer == "Yes")||(Answer == "yes")||(Answer == "Y")||(Answer == "y")){
        return true;    
    }

    return false;

}

long getNumberOfDigits(long NumValue){
    
    return (NumValue == 0? 1: int (log10 (NumValue) + 1));
}

long getSumOfDigitsNum(long NumValue){
    
    constexpr auto DIVIDER_CONST_TEN{10};
    long SumNumValue{};

    for(auto ModifyValue{NumValue}; ModifyValue >= 1; (ModifyValue/=DIVIDER_CONST_TEN)){
        SumNumValue += ModifyValue%DIVIDER_CONST_TEN;
    }

    return SumNumValue;
}

long getSignAttribute(long NumValue){
    
    if (NumValue < 0){
        return -1;
    }

    return 1;
}

int calcSumArithmeticMean(){
       
    long InputValue{};
    
    std::cout << "'Sum and arithmeric mean numbers'\n\n"
              << "Please, enter integer value: ";
    std::cin >> InputValue;
    
    auto SizeValue{getNumberOfDigits(InputValue)};    
    auto SumNumValue{getSumOfDigitsNum(InputValue)};
    
    std::cout << "\n"
              << "Sum of digits: " << SumNumValue << ".\n"
              << "Average of the sum of digits: " << (SumNumValue/SizeValue) << ".\n";

    return 0;
}

int calcLuckyTicket(){
    
    constexpr auto DIVIDER_CONST_TEN{10};
    constexpr auto DIGIT_CAPACITY_CONST_SIX{6};
    const auto CONST_THREE{static_cast<int>(pow(DIVIDER_CONST_TEN,(DIGIT_CAPACITY_CONST_SIX/2)))};
   
    long InputValue{}, SizeValue{};
    
    std::cout << "'Lucky ticket'\n\n";

    for(;;){
    
        std::cout << "Please, enter six value numbers: ";
        std::cin >> InputValue;
        std::cout << ".\n";

        SizeValue = getNumberOfDigits(InputValue);
        
        if(SizeValue == DIGIT_CAPACITY_CONST_SIX){
            break;
        }

        std::cout << "You entered the wrong number: " << InputValue << ".\n"
                << "Enter new value? [Y/n]: ";
        if(getContinueTheProgram()){
            std::cout << ".\n"; 
            continue;
        }        
        return 1; 
    }

    auto FirstThreeDigits{getSumOfDigitsNum(InputValue % CONST_THREE)};
    auto LastThreeDigits{getSumOfDigitsNum(InputValue / CONST_THREE)};  
    
    if(FirstThreeDigits == LastThreeDigits){
        std::cout << "\tYou wins!!!\n Sum first and last digets number " << InputValue << " coincided\n";
        return 0;
    }
    std::cout << "\tYou lost!!!\n Sum first and last digets number " << InputValue << " did not match\n";
    return 0;
}

int calcReverseNumber(){
    
    constexpr auto DIVIDER_CONST_TEN{10};

    long InputValue{}, ReversValue{};
    
    std::cout << "'Reverse number'\n\n"
              << "Please, enter integer value: ";
    std::cin >> InputValue;
    
    for(auto ModifeValue{InputValue*getSignAttribute(InputValue)}; 
            ModifeValue >= 1;
            ModifeValue/=DIVIDER_CONST_TEN, (ModifeValue ? ReversValue*=DIVIDER_CONST_TEN : ReversValue)){
        ReversValue += ModifeValue % DIVIDER_CONST_TEN;
    }

    ReversValue *= getSignAttribute(InputValue);
    std::cout << "Input value: " << InputValue << "\n"
            << "Revers value: " << ReversValue << "\n";

    return 0;        

}

int main(){

    std::cout << "Select the required action from the list\n"
        << "\t1 - Sum and arithmetic mean of digits.\n"
        << "\t2 - Lucky ticket.\n"
        << "\t3 - Reverse number.\n";
            
    long IdAct{};
    std::cin >> IdAct;

    switch (IdAct){
    case 1:
        calcSumArithmeticMean();
        break;
    case 2:
        calcLuckyTicket();
        break;
    case 3:
        calcReverseNumber();
        break;
    default:
        std::cout << "You chose the wrong action\n";
        break;
    }

    std::cout << "Do you want to continue running the program? [Y/n]: ";
    
    if (getContinueTheProgram()){
        main();
    }

    return 0;
}