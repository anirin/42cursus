-- `users` テーブルにデータを挿入
INSERT INTO `users` (`user_id`, `name`) VALUES
(1, 'Alice'),
(2, 'Bob'),
(3, 'Charlie'),
(4, 'David'),
(5, 'Eve'),
(6, 'Frank'),
(7, 'Grace'),
(8, 'Helen');

-- `friend_link` テーブルに友達関係を挿入
INSERT INTO `friend_link` (`user1_id`, `user2_id`) VALUES
(1, 2), -- Alice と Bob
(1, 3), -- Alice と Charlie
(2, 4), -- Bob と David
(3, 4), -- Charlie と David
(5, 6), -- Eve と Frank
(7, 8); -- Grace と Helen

-- `block_list` テーブルにブロック情報を挿入
INSERT INTO `block_list` (`user1_id`, `user2_id`) VALUES
(1, 4), -- Alice が David をブロック
(2, 3), -- Bob が Charlie をブロック
(5, 7), -- Eve が Grace をブロック
(6, 8); -- Frank が Helen をブロック
