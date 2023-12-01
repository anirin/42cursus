INSERT INTO `users` (`user_id`, `name`) VALUES
(1, 'User A'),
(2, 'User B'),
(3, 'User C'),
(4, 'User D'),
(5, 'User E'),
(6, 'User F'),
(7, 'User G'),
(8, 'User H'),
(9, 'User I'),
(10, 'User J');

INSERT INTO `friend_link` (`user1_id`, `user2_id`) VALUES
(1, 2), (1, 3), (1, 4), (2, 3), (2, 5),
(3, 6), (4, 5), (4, 7), (5, 8), (6, 7),
(6, 9), (7, 8), (8, 9), (9, 10), (10, 1),
(2, 6), (3, 7), (5, 9), (4, 10), (2, 8);

INSERT INTO `block_list` (`user1_id`, `user2_id`) VALUES
(1, 5), (2, 6), (3, 7),
(4, 8), (5, 9), (6, 10);
