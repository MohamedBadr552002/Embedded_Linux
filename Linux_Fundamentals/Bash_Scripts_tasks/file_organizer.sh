#!/usr/bin/bash



# Check if the directory exists
if [ ! -d "$1" ]; then
  echo "Error: Directory $DIR does not exist."
  exit 1
fi

for filename in `ls -a $1`; do

    # Handle special cases for hidden files
    if [ "${filename}" == "." ] || [ "${filename}" == ".." ];then
        continue
    fi

    declare file_path="$1/${filename}"
    
    # extenstions extraction
    declare extension=${filename##*.}
    

    # Handle files with no extension or dotfiles (hidden files)
    if [[ "$filename" == "$extension" ]] || [[ "${filename##*/}" == .* ]]; then
      extension="misc"
    fi



    # extenstions checking 
    declare directory_name="${extension}_files"

    declare directory_path="$1/${directory_name}"
   

    if [ -d "${directory_path}" ]; then
        mv ${file_path} ${directory_path} 
    else
        mkdir ${directory_path}
        mv ${file_path} ${directory_path} 
    fi        


   
    
   
done

 echo "======== diretory has been Organized :) ==========="

 tree -a 

