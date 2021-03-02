#include <iostream>

int main(){
	std::cout << "\e[1mMake sure you have sudo installed and configured \e[0m\n\n";
	while(true){
		std::cout << "	\e[1m SYSTEM \e[0m\n";
		std::cout << "1. startup > /usr/bin\n";	
		std::cout << "2. Disable double click prevention\n";
		std::cout << "3. make.conf > /etc/portage\n";
	
		std::cout << "	\e[1m PROGRAMS \e[0m\n";
		std::cout << "4. dwm\n";	
		std::cout << "5. st\n";
		std::cout << "6. yay (arch only)\n";
		std::cout << "7. picom (fork)\n";
		std::cout << "8. librewolf\n";
	
		std::cout << "	\e[1m CONFIG \e[0m\n";
		std::cout << "9. librewolf cosmetic theme (must have librewolf installed)\n";
		std::cout << "10. picom.conf (must have picom installed)\n";
	
		int in;
		std::cin >> in;
		switch(in){
			case(1):
				system("sudo cp sys/startup /usr/bin");
				break;
			case(2):
				system("sudo sys/LowerDebounceTime");				
				break;
			case(3):
				system("sudo cp sys/make.conf /etc/portage");
				break;
			case(4):
				system("cd prgms/dwm && sudo make clean install && cd ../..");
				break;
			case(5):
				system("cd prgms/st && sudo make clean install && cd ../..");
				break;
			case(6):
				system("sudo pacman -S --needed git base-devel && git clone https://aur.archlinux.org/yay.git && cd yay && makepkg -si && cd .. && rm -rf yay");
				break;
			case(7):
				std::cout << "If you are on arch, installing from the AUR would be better. Make sure you have all required dependencies to build this (https://github.com/yshui/picom/blob/next/README.md#dependencies)\n";
				system("git clone https://github.com/ibhagwan/picom && cd picom && sudo git submodule update --init --recursive && sudo meson --buildtype=release . build && sudo ninja -C build && sudo ninja -C build install && cd .. && sudo rm -rf picom/");
				break;
			case(8):
				std::cout << "I recommend looking in your distrobutions repositories first as it would be better to install from there.\n";
				std::cout << "AUR(Arch only, Doesn't require an aur helper)(1) or AppImage(2): ";
				in = 0;
				std::cin >> in;
				if(in == 1) system("git clone https://aur.archlinux.org/librewolf-bin.git librewolf && cd librewolf && makepkg -si");
				else if(in == 2) system("echo \"Make sure you have curl and FUSE on your system.\" && curl https://gitlab.com/librewolf-community/browser/linux/uploads/e15c18d46b8e07ac18bf7f59a976c9e0/LibreWolf-86.0-1.x86_64.AppImage --output librewolf && chmod +x librewolf && sudo mv librewolf /usr/bin");
				break;
			case(9):
				std::cout << "Make sure to read the prerequisites first: https://github.com/mut-ex/minimal-functional-fox#prerequisites\n";
				system("sudo cp -r cfg/librewolf/chrome ~/.librewolf/*.default-release");
				break;
			case(10):
				system("sudo cp cfg/picom.conf /etc/xdg");
				break;
			default:
				std::cout << "Invalid choice\n";
				break;
		}
	}
}
