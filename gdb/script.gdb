define print-variables
  print "Contenu_de_R0_:_" $r0
end

break f
run
watch x
print-variables

