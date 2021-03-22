#include <simple_test_framework/Test.hpp>
#include <chess/chess.hpp>

INIT_TEST_FRAMEWORK

TEST(createLayout)
{
   std::string lay =  "wc4a5h8";

   ASSERT_EQ("c4", getWKingPosition(lay));
   ASSERT_EQ("a5", getWRookPosition(lay));
   ASSERT_EQ("h8", getBKingPosition(lay));
};

TEST(canMove_RookCannotMoveToPositionItAlreadyIs)
{
   std::string lay("wd4f3h1");
   ASSERT_FALSE(canWRookMove(lay,"f3"));
};

TEST(canMove_RookCanMoveToRightBy1)
{
   std::string lay("wh8g5h6");
   ASSERT_TRUE(canWRookMove(lay, "h5"));
};

TEST(canMove_RookCannotJumpOverKing)
{
   std::string lay("wc5e5e7");
   ASSERT_FALSE(canWRookMove(lay, "a5"));
   ASSERT_FALSE(canWRookMove(lay, "e8"));
};

TEST(WRook_possibleMoveLayouts)
{
   std::vector<std::string> exp{ "bh8a5h6",
                                 "bh8b5h6",
                                 "bh8c5h6",
                                 "bh8d5h6",
                                 "bh8e5h6",
                                 "bh8f5h6",
                                 "bh8h5h6",
                                 "bh8g1h6",
                                 "bh8g2h6",
                                 "bh8g3h6",
                                 "bh8g4h6",
                                 "bh8g6h6",
                                 "bh8g7h6",
                                 "bh8g8h6"};
                                 
   std::string lay("wh8g5h6");
   ASSERT_EQ(possibleWRookMoveLayouts(lay), Layouts(exp));
};

TEST(WRook_possibleMoveLayouts_RookCannotJumpOverKing)
{
   std::string lay("wc5e5e7");
   std::vector<std::string> exp = { "bc5d5e7",
                                    "bc5f5e7",
                                    "bc5g5e7",
                                    "bc5h5e7",
                                    "bc5e1e7",
                                    "bc5e2e7",
                                    "bc5e3e7",
                                    "bc5e4e7",
                                    "bc5e6e7",
                                 };

   ASSERT_TRUE(canWRookMove(lay,"g5"));
   ASSERT_EQ(possibleWRookMoveLayouts(lay), Layouts(exp));

};

TEST(BKing_possibleMoveLayouts_KingCannotMoveTOCheck)
{
   std::string lay("bh1h2c1");
   std::vector<std::string> exp = {"wh1h2b1", "wh1h2d1"};
   ASSERT_EQ(possibleBKingMoveLayouts(lay), Layouts(exp));
};

TEST(BKing_possibleMoveLayouts_KingCannotMoveTOCheckByWhiteKing)
{
   std::string lay("bc3h1a3");
   std::vector<std::string> exp = {"wc3h1a2", "wc3h1a4"};
   ASSERT_EQ(possibleBKingMoveLayouts(lay), Layouts(exp));
};

TEST(WKing_possibleMoveLayouts_KingCannotMoveTOCheckByBlackKing)
{
   std::string lay("bc3h1a3");
   std::vector<std::string> exp = {"wc2h1a3",
                                   "wc4h1a3",
                                   "wd2h1a3",
                                   "wd3h1a3",
                                   "wd4h1a3"};

   ASSERT_EQ(possibleWKingMoveLayouts(lay), Layouts(exp));
};

TEST(WKing_possibleMoveLayouts_KingCannotMove)
{
   std::string lay("ba1a2c2");
   std::vector<std::string> exp = {};
   ASSERT_EQ(possibleWKingMoveLayouts(lay), Layouts(exp));
};

TEST(chess_onCheckMate_0moves)
{
   std::string lay("wh6a4d4");
   chess ch(lay);

   ASSERT_EQ(ch.getMinNumOfMoves(), 9);
};

TEST(WRook_possibleMoveLayouts_RookCannotGoOnDangerField)
{
   std::string lay("wc2e1a2");
   ASSERT_FALSE(canWRookMove(lay,"a1"));
};

RUN_TESTS