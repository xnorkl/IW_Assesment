declare -a repos=($(find . -type d -name '[[:upper:]]*'))
parentdir=$HOME/Task6
for r in "${repos[@]}"
do
	cd "$r"
	pwd
	#git checkout development
	cd "$parentdir"
	#git add "$r"
	#git commit -m "updated submodule to development"
	
done

