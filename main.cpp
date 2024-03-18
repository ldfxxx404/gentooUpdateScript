#include <iostream>
#include <cstdlib>

/*Gentoo update script. Doas edition*/

int main(){

    int option;
    
    std::cout << "This is Gentoo update script. You should select option." << std::endl;
    std::cout << "1 - update Gentoo repo" << std::endl;
    std::cout << "2 - update packages" << std::endl;
    std::cout << "3 - grub install" << std::endl;
    std::cout << "4 - make grub.cfg" << std::endl;
    /*std::cout << "5 - autoupdate all" << std::endl;*/

    std::cout << "Choose your option: ";

    std::cin >> option;

    switch (option) {

        /*Update*/

        case 1:
            std::cout << "Update synchronization. Enter your password" << std::endl;
            system("doas emaint -a sync");
            break;
        case 2:
            std::cout << "Package update. Enter your password" << std::endl;
            system("doas emerge --ask --verbose --update --deep --newuse @world");
            break;
        case 3:
            std::cout << "Grub update. Enter your password" << std::endl;
            system("doas grub-install --efi-directory=/boot");
            break;
        case 4:
            std::cout << "Create grub.cfg. Enter your password" << std::endl;
            system("doas grub-mkconfig -o /boot/grub/grub.cfg");
            std::cerr << "grub.cfg is created!" << std::endl;
            break;

        /*case 5:
            std::cout<< "Perform previous steps automatically" << std::endl;
            system("doas emaint -a sync && emerge --ask --verbose --update --deep --newuse @world && grub-install --efi-directory=/boot && grub-mkconfig -o /boot/grub/grub.cfg");*/

        default:
            std::cout << "Error";


    }


    return 0;
}