#ifndef __UNITY_HELPER_H__
# define __UNITY_HELPER_H__

# define TEST_MISSING() (TEST_IGNORE_MESSAGE("test missing"))
# define TEST_ASSERT_INT_DATA(exp, act) (TEST_ASSERT_EQUAL((exp), *(int*)(act)))
# define TEST_ASSERT_LESS_INT_DATA(lesser, x) if (*(int*)(lesser) < *(int*)(x)) {} \
                                              else { TEST_FAIL_MESSAGE("should be less"); }

#endif
