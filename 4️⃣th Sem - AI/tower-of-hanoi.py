def tower_of_hanoi_generalized(n, source, target, auxiliary_towers, move_count):
    if n == 0:
        return move_count
    if len(auxiliary_towers) == 0:
        print(f"Move disk {n} from {source} to {target}")
        return move_count + 1
    temp_target = auxiliary_towers[0]
    remaining_auxiliary = auxiliary_towers[1:]
    move_count = tower_of_hanoi_generalized(
        n - 1, source, temp_target, remaining_auxiliary + [target], move_count
    )
    print(f"Move disk {n} from {source} to {target}")
    move_count += 1
    move_count = tower_of_hanoi_generalized(
        n - 1, temp_target, target, remaining_auxiliary + [source], move_count
    )
    return move_count


if __name__ == "__main__":
    num_disks = int(input("Enter the number of disks: "))
    num_towers = int(input("Enter the number of towers (minimum 3): "))

    if num_towers < 3:
        print("The number of towers must be at least 3.")
    else:
        towers = [chr(65 + i) for i in range(num_towers)]
        source_tower = towers[0]
        target_tower = towers[1]
        auxiliary_towers = towers[2:]

        move_count = tower_of_hanoi_generalized(
            num_disks, source_tower, target_tower, auxiliary_towers, 0
        )
        print(f"Total moves: {move_count}")
