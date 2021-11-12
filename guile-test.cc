#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>

#include <libguile.h>

static SCM
my_pythagoras(SCM _a, SCM _b){
    double a = scm_to_double(_a);
    double b = scm_to_double(_b);
    return scm_from_double(std::sqrt(a*a + b*b));
}

static SCM
my_gettime(void)
{
    struct timespec ts = {};
    int ret = clock_gettime(CLOCK_REALTIME, &ts);
    if(ret < 0){
        return SCM_BOOL_F;
    }
    return scm_cons(scm_from_uint64(ts.tv_sec), scm_from_uint64(ts.tv_nsec));

}

static SCM
my_hostname(void)
{
    char *s = getenv("HOSTNAME");
    if (s == NULL)
        scm_misc_error(__func__, "HOSTNAME env variable is null", SCM_BOOL_F);
    else
        return scm_from_locale_string(s);
}

static void
inner_main(void *data, int argc, char **argv)
{
    (void)data;
    scm_c_define_gsubr("my-hostname", 0, 0, 0, reinterpret_cast<scm_t_subr>(my_hostname));
    scm_c_define_gsubr("my-gettime", 0, 0, 0, reinterpret_cast<scm_t_subr>(my_gettime));
    scm_c_define_gsubr("my-pythagoras", 2, 0, 0, reinterpret_cast<scm_t_subr>(my_pythagoras));
    scm_shell(argc, argv);
}

int main(int argc, char **argv)
{
    scm_boot_guile(argc, argv, inner_main, 0);
    return 0; /* never reached */
}
