# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    canonical.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 00:20:57 by mabbas            #+#    #+#              #
#    Updated: 2023/09/20 00:20:58 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##

import sys
import re
import argparse

def inject_orthodox_canonical_form(file, name):
    try:
        with open(file, 'r') as f:
            content = f.read()
    except FileNotFoundError:
        print(f"The file {file} could not be opened.")
        return

    pattern = r"class\s+" + name + r"\s*{"
    replacement = r"\g<0>\npublic:\n\t" + name + "();\n\t~" + name + "();\n\t" + name + "(const " + name + "&);\n\t" + name + "& operator=(const " + name + "&);"
    modified_content = re.sub(pattern, replacement, content)

    try:
        with open(file, 'w') as f:
            f.write(modified_content)
        print("The code has been injected successfully.")
    except IOError:
        print(f"The file {file} could not be written.")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Inject constructor, destructor, and copy constructor into a class in a C++ file.")
    parser.add_argument('file_and_name', type=str, help="The C++ file and class name to modify, separated by a comma.")

    args = parser.parse_args()

    file, name = args.file_and_name.split(',')
    inject_orthodox_canonical_form(file.strip(), name.strip())