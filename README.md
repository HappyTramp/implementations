# Implementations

Some implementation of algorithms

## Testing

Unit test made with [Unity](https://www.throwtheswitch.org/unity) and built with [Ceedling](https://www.throwtheswitch.org/ceedling)

Install Ceedling:
```
> gem install ceedling
```

Clone this repo and cd into it.

Run those real hacker commands (just setting up the environment):
```
> mv project.yml project.yml.backup # dirty
> ceedling new .
> mv project.yml.backup project.yml # my eyes are bleeding
```

Test everything:
```
> ceedling test:all
```
