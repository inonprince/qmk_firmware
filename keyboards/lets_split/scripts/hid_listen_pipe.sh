# KWM focus
cmd_KWM_FOCUS_WEST () { open -g "kwmc window -f west"; }
cmd_KWM_FOCUS_SOUTH () { open -g "kwmc window -f south"; }
cmd_KWM_FOCUS_NORTH () { open -g "kwmc window -f north"; }
cmd_KWM_FOCUS_EAST () { open -g "kwmc window -f east"; }
cmd_KWM_FOCUS_LAST () { open -g "hammerspoon://focus-last"; }
cmd_KWM_FOCUS_PREV () { open -g "kwmc window -fm prev;"; }
cmd_KWM_FOCUS_NEXT () { open -g "kwmc window -fm next;"; }
cmd_KWM_FOCUS_DISPLAY_0 () { open -g "kwmc display -f 0"; }
cmd_KWM_FOCUS_DISPLAY_1 () { open -g "kwmc display -f 1"; }
cmd_KWM_FOCUS_DISPLAY_2 () { open -g "kwmc display -f 2"; }

# KWM swap
cmd_KWM_SWAP_WEST () { open -g "hammerspoon://smartMove-left"; }
cmd_KWM_SWAP_SOUTH () { open -g "hammerspoon://smartMove-down"; }
cmd_KWM_SWAP_NORTH () { open -g "hammerspoon://smartMove-up"; }
cmd_KWM_SWAP_EAST () { open -g "hammerspoon://smartMove-right"; }
cmd_KWM_SWAP_MARKED () { open -g "kwmc window -s mark"; }

# KWM move
cmd_KWM_MOVE_WEST () { open -g "kwmc window -m west"; }
cmd_KWM_MOVE_SOUTH () { open -g "kwmc window -m south"; }
cmd_KWM_MOVE_NORTH () { open -g "kwmc window -m north"; }
cmd_KWM_MOVE_EAST () { open -g "kwmc window -m east"; }
cmd_KWM_MOVE_MARKED () { open -g "kwmc window -m mark"; }
cmd_KWM_MOVE_SPACE_LEFT () { open -g "hammerspoon://smartMove-spaceLeft"; }
cmd_KWM_MOVE_SPACE_RIGHT () { open -g "hammerspoon://smartMove-spaceRight"; }
cmd_KWM_MOVE_SPACE_1 () { open -g "kwmc window -m space 1"; }
cmd_KWM_MOVE_SPACE_2 () { open -g "kwmc window -m space 2"; }
cmd_KWM_MOVE_SPACE_3 () { open -g "kwmc window -m space 3"; }
cmd_KWM_MOVE_SPACE_4 () { open -g "kwmc window -m space 4"; }
cmd_KWM_MOVE_SPACE_5 () { open -g "kwmc window -m space 5"; }
cmd_KWM_MOVE_SPACE_6 () { open -g "kwmc window -m space 6"; }
cmd_KWM_MOVE_SPACE_7 () { open -g "kwmc window -m space 7"; }
cmd_KWM_MOVE_NEWSPACE () { open -g "hammerspoon://smartMove-newSpace"; }
cmd_KWM_MOVE_DISPLAY_PREV () { open -g "hammerspoon://smartMove-displayPrev"; }
cmd_KWM_MOVE_DISPLAY_NEXT () { open -g "hammerspoon://smartMove-displayNext"; }
cmd_KWM_MOVE_DISPAY_0 () { open -g "kwmc window -m display 0"; }
cmd_KWM_MOVE_DISPAY_1 () { open -g "kwmc window -m display 1"; }
cmd_KWM_MOVE_DISPAY_2 () { open -g "kwmc window -m display 2"; }

# KWM spaces
cmd_KWM_SPACE_MOVETO_1 () { open -g "kwmc space -fExperimental 1"; }
cmd_KWM_SPACE_MOVETO_2 () { open -g "kwmc space -fExperimental 2"; }
cmd_KWM_SPACE_MOVETO_3 () { open -g "kwmc space -fExperimental 3"; }
cmd_KWM_SPACE_MOVETO_4 () { open -g "kwmc space -fExperimental 4"; }
cmd_KWM_SPACE_MOVETO_5 () { open -g "kwmc space -fExperimental 5"; }
cmd_KWM_SPACE_MOVETO_6 () { open -g "kwmc space -fExperimental 6"; }
cmd_KWM_SPACE_MOVETO_7 () { open -g "kwmc space -fExperimental 7"; }
cmd_KWM_SPACE_MOVETO_8 () { open -g "kwmc space -fExperimental 8"; }
cmd_KWM_SPACE_MOVETO_9 () { open -g "kwmc space -fExperimental 9"; }
cmd_KWM_SPACE_MOVETO_LEFT () { open -g "kwmc space -fExperimental left && killall Dock"; }
cmd_KWM_SPACE_MOVETO_RIGHT () { open -g "kwmc space -fExperimental right && killall Dock"; }
cmd_KWM_SPACE_MOVETO_PREV () { open -g "kwmc space -fExperimental previous && killall Dock"; }
cmd_KWM_SPACE_REMOVE () { open -g "hammerspoon://smartMove-removeSpace"; }
cmd_KWM_SPACE_BSP () { open -g "kwmc space -t bsp"; }
cmd_KWM_SPACE_MONOCLE () { open -g "kwmc space -t monocle"; }

# KWM tree
cmd_KWM_TREE_FULLSCREEN () { open -g "kwmc window -z fullscreen"; }
cmd_KWM_TREE_PARENT () { open -g "kwmc window -z parent"; }
cmd_KWM_TREE_FLOAT () { open -g "hammerspoon://tree-float"; }
cmd_KWM_TREE_ROTATE () { open -g "hammerspoon://tree-rotate"; }
cmd_KWM_TREE_TOGGLESPLIT () { open -g "hammerspoon://tree-toggle"; }
cmd_KWM_RESIZE_WEST () { open -g "hammerspoon://smartResize-thinner"; }
cmd_KWM_RESIZE_SOUTH () { open -g "hammerspoon://smartResize-shorter"; }
cmd_KWM_RESIZE_NORTH () { open -g "hammerspoon://smartResize-taller"; }
cmd_KWM_RESIZE_EAST () { open -g "hammerspoon://smartResize-wider"; }

# KWM misc
cmd_KWM_MARK () { open -g "kwmc window -mk focused"; }


while true
do
  echo running...
  ./hid_listen.mac |
    while IFS= read -r line
    do
      case "$line" in
        "CMD:"*)
            ;;
        *)
            continue
            ;;
      esac
      
      cmd="$(echo $line | cut -d: -f2-)"
      echo "CMD: $cmd"
      
      if type cmd_${cmd} >/dev/null 2>&1; then
        cmd_${cmd}
      else
        echo "no matching function"
      fi

    done
  sleep 2
done