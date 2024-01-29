#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &source)
    : AForm(source.getName(), source.getGradeToSign(),
            source.getGradeToExecute()) {
  *this = source;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source) {
  if (this == &source) {
    return *this;
  }
  this->target = source.target;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::string ShrubberyCreationForm::getTarget() const { return this->target; }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned() || executor.getGrade() > this->getGradeToExecute()) {
    throw GradeTooLowException();
  }
  std::ofstream ofs((this->getName() + "_shrubbery").c_str());
  if (!ofs.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return;
  }
  ofs << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
  ofs << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
  ofs << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
  ofs << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
  ofs << "        {/{/(_)/}{\\{/)_\\}\\{\\(_){/}/}/}/}" << std::endl;
  ofs << "         {\\{/(_\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
  ofs << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_)\\{\\/}\\}" << std::endl;
  ofs << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
  ofs << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
  ofs << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
  ofs << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
  ofs << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
  ofs << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
  ofs << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
  ofs << "          (_)\\{/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
  ofs << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
  ofs << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
  ofs << "              {)\\{\\/}{\\/} \\}\\}" << std::endl;
  ofs << "              (_)  \\.- .-/" << std::endl;
  ofs << "                    | -.- |" << std::endl;
  ofs << "                    | -.- |" << std::endl;
  ofs << "                    |. -._|" << std::endl;
  ofs << "                    |  -. |" << std::endl;
  ofs << "                    | -_.-|" << std::endl;
  ofs << "                    |-._ -|" << std::endl;
  ofs << "                    | - .-|" << std::endl;
  ofs << "                    `-._.- " << std::endl;
  ofs.close();
}
