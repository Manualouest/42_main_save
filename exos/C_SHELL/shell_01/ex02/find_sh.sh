find -name '*.sh' | sed -r 's/.{3}$//' | rev | cut -d '/' -f1 | rev
