#ifndef __UNITY_HELPER_H__
# define __UNITY_HELPER_H__

# define TEST_MISSING() (TEST_IGNORE_MESSAGE("test missing"))
# define TEST_ASSERT_INT_DATA(exp, act) (TEST_ASSERT_EQUAL((exp), *(int*)(act)))

#endif
